/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:59:24 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 11:49:54 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_signal(int exit_status)
{
	int	ret;
	int sig;

	ret = 0;
	sig = 0;
	if (WIFEXITED(exit_status))
		ret = WEXITSTATUS(exit_status);
	if (WIFSIGNALED(exit_status))
		sig = WTERMSIG(exit_status);
	if (sig)
		ret = sig + 128;
	return (ret);
}

void	wait_cmds(int n, int last_pid)
{
	int	pid;
	int	exit_status;

	while (n)
	{
		exit_status = 0;
		pid = waitpid(0, &exit_status, 0);
		exit_status = get_signal(exit_status);
		if (pid == last_pid)
			gs_info()->exit_status = exit_status;
		n--;
	}
	if (exit_status > 128)
		write(1, "\n", 1);
	gs_info()->last_exit_status = gs_info()->exit_status;
}
