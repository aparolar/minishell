/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:58:03 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/08 18:22:18 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*expand_herdoc(char *line)
{
	char		*next;
	char		*expanded;
	t_expansion	exp;

	exp.index = 0;
	next = ft_strchr(line, '$');
	if (!next)
		expanded = ft_strdup(line);
	else
	{
		exp.str = ft_strdup(line);
		exp.index = get_index(exp.str, '$');
		exp.dquote.index = exp.index;
		exp.value = ft_strdup(line);
		copy_to_expand(&exp);
		expanded = ft_strdup(exp.value);
		free(exp.str);
		free(exp.value);
	}
	return (expanded);
}

static void	on_signal(int signo)
{
	(void)signo;
	ft_putchar_fd('\n', 2);
	exit(130);
}

static void	read_heredoc(t_command *cmd, t_token *token)
{
	char	*line;
	char	*tmp;
	int		expand;

	expand = maybe_expand(token);
	if (expand)
		remove_quotes(token);
	line = readline("> ");
	while (line)
	{
		tmp = line;
		if (ft_strcmp(token->start, line))
		{
			free(line);
			break ;
		}
		if (!expand)
			line = expand_herdoc(line);
		ft_putendl_fd(line, cmd->fd_in);
		free(tmp);
		if (!expand)
			free(line);
		line = readline("> ");
	}
}

void	get_heredoc(t_command *cmd, t_token *token)
{
	int		pid;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	cmd->fd_in = open("/tmp/.hd_tmp", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (cmd->fd_in >= 0 && pid == 0)
	{
		signal(SIGINT, on_signal);
		read_heredoc(cmd, token);
		close(cmd->fd_in);
		exit(0);
	}
	waitpid(pid, &gs_info()->exit_status, 0);
	signal(SIGINT, on_father_signal);
}
