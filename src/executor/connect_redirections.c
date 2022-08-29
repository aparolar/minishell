/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:18 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/26 14:00:57 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	connect_redirections(int fd_in, t_command *cmd)
{
	if (fd_in)
		dup2(fd_in, STDIN_FILENO);
	close(cmd->fd[0]);
	if (cmd->fd[1] != 1)
		dup2(cmd->fd[1], STDOUT_FILENO);
	if (ft_lstsize(cmd->redir) > 0)
	{
		if (cmd->fd_in > -1)
			dup2(cmd->fd_in, STDIN_FILENO);
		if (cmd->fd_out > -1)
			dup2(cmd->fd_out, STDOUT_FILENO);
	}
}
