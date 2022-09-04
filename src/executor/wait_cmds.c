/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:59:24 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/04 20:48:27 by aparolar         ###   ########.fr       */
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
		//printf("WIF %i WEX %i WIFS %i\n", WIFEXITED(exit_status), WEXITSTATUS(exit_status), WIFSIGNALED(exit_status));
		if (WIFEXITED(exit_status) && !WIFSIGNALED(exit_status))
			exit_status = WEXITSTATUS(exit_status);
		else if (!WIFEXITED(exit_status) && WIFSIGNALED(exit_status))
			exit_status = 130;
		if (pid == last_pid)
			gs_info()->exit_status = exit_status;
		n--;
	}
	gs_info()->last_exit_status = gs_info()->exit_status;
}
