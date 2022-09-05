/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:19:09 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 17:15:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_output_redirs(t_command *cmd)
{
	t_token	*token;

	if (!cmd->redir)
		return (0);
	token = cmd->redir->content;
	while (token)
	{
		if (token->flags & TOKEN_IO)
		{
			if (is_directory(token->start))
			{
				printf(MS_ERR_IS_DIR);
				gs_info()->exit_status = 1;
				return (1);
			}
		}
		if (token->node->next)
			token = token->node->next->content;
		else
			token = NULL;
	}
	return (0);
}

static void	do_fork(char *str_cmd, int fd_in, t_command *cmd)
{
	char	**env;
	char	**argv;

	errno = 0;
	execute_heredocs(cmd);
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		if (gs_info()->exit_status)
			exit(0);
		get_redirections(cmd);
		connect_redirections(fd_in, cmd);
		argv = get_array_from_token_lst(cmd->argv);
		env = get_env_array();
		cmd->result = execve(str_cmd, argv, env);
		if (cmd->result == -1)
			show_error(cmd, str_cmd);
		exit(cmd->result);
	}
	father_close_fds(fd_in, cmd);
}

int	execute(int fd_in, t_command *cmd)
{
	t_token	*token;
	char	*str_cmd;

	str_cmd = NULL;
	if (check_output_redirs(cmd))
		return (1);
	if (cmd->argv)
	{
		token = cmd->argv->content;
		str_cmd = find_command(token->start);
	}
	if (!str_cmd && cmd->argv)
	{
		access("", F_OK);
		show_error(cmd, token->start);
		return (0);
	}
	do_fork(str_cmd, fd_in, cmd);
	free(str_cmd);
	return (0);
}
