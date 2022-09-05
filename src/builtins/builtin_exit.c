/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:39:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 13:17:47 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pre_exit(t_command *cmd)
{
	int		result;
	char	**argv;
	_Bool	silence;

	result = 255;
	silence = (ft_lstsize(gs_info()->cmd_lst) > 1);
	argv = get_array_from_token_lst(cmd->argv);
	if (!silence)
		ft_putstr_fd("exit\n", 1);
	if (ft_array_count(argv) > 1)
	{
		if (ft_is_valid_aint(argv[1]))
			result = ft_atoi(argv[1]);
		else if (!silence)
			ft_putstr("numeric argument required\n");
		if (!silence)
			exit_controlled(result);
	}
	if (!silence)
		exit_controlled(0);
	gs_info()->last_exit_status = result;
}

void	builtin_exit(t_command *cmd)
{
	(void)cmd;
	exit(gs_info()->last_exit_status);
}
