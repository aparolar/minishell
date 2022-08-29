/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father_close_fds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:24:49 by aparolar          #+#    #+#             */
/*   Updated: 2022/07/02 12:51:14 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	father_close_fds(int fd_in, t_command *cmd)
{
	if (fd_in)
		close(fd_in);
	if (cmd->fd[1] != 1)
		close(cmd->fd[1]);
}
