/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:59:24 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/03 19:27:56 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_cmds(int n, int last_pid)
{
	int	pid;
	int	exit_status;

	while (n)
	{
		exit_status = 0;
		pid = waitpid(0, &exit_status, 0);
		exit_status = WEXITSTATUS(exit_status);
		if (pid == last_pid)
			gs_info()->exit_status = exit_status;
		n--;
	}
}
