/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:21:03 by aparolar          #+#    #+#             */
/*   Updated: 2022/07/02 12:53:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_builtin_fork(int fd_in, t_command *cmd,
			void (*f)(t_command *cmd))
{
	errno = 0;
	execute_heredocs(cmd);
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		get_redirections(cmd);
		connect_redirections(fd_in, cmd);
		f(cmd);
		exit(0);
	}
	else
		father_close_fds(fd_in, cmd);
}
