/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:39:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/29 21:59:47 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pre_exit(t_command *cmd)
{
	if (ft_lstsize(gs_info()->cmd_lst) == 1)
	{
		ft_putstr_fd("exit\n", 1);
		system("lsof | grep \"minishell \" | grep \" CHR \"");
		exit_controlled(0);
	}
}

void	builtin_exit(t_command *cmd)
{
	exit(0);
}
