/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:18:43 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/03 23:50:55 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_command	*exec_new(int fd_in, t_command *cmd, t_env_node *env)
{
	t_token	*token;
	char	*str_cmd;

	(void)env;
	if (cmd->argv)
	{
		token = cmd->argv->content;
		str_cmd = token->start;
	}
	else
		str_cmd = "";
	if (is_builtin(str_cmd))
		execute_builtin(fd_in, token->start, cmd);
	else
		execute(fd_in, cmd);
	return (get_next_command(cmd));
}

static void	copy_cmd_fds(int *fds_in, int *fds_out)
{
	fds_out[0] = fds_in[0];
	fds_out[1] = fds_in[1];
}

int	execute_cmd(t_list *cmd_lst, t_env_node *env_lst)
{
	t_command	*cmd;
	t_command	*prev;
	int			fd_in;
	int			fd[2];

	prev = NULL;
	cmd = cmd_lst->content;
	fd_in = 0;
	while (cmd)
	{
		if (cmd->node->next)
			pipe(fd);
		else
			fd[1] = 1;
		copy_cmd_fds(fd, cmd->fd);
		cmd = exec_new(fd_in, cmd, env_lst);
		fd_in = fd[0];
	}
	disable_main_signals();
	wait_cmds(ft_lstsize(cmd_lst), get_last_command(cmd_lst)->pid);
	write(2, "\n", 1);
	init_main_signals();
	return (0);
}
