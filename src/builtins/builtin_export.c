/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:33:33 by icastell          #+#    #+#             */
/*   Updated: 2022/06/28 18:03:47 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pre_export(t_command *cmd)
{
	char	**argv;

	argv = get_array_from_token_lst(cmd->argv);
	if ((argv) && (ft_array_count(argv)) > 0)
	{
		if (ft_array_count(argv) > 1)
			builtin_export_var(argv);
		free(argv);
	}
	return ;
}

void	builtin_export(t_command *cmd)
{
	char	**argv;

	argv = get_array_from_token_lst(cmd->argv);
	if ((argv) && (ft_array_count(argv)) > 0)
	{
		if (ft_array_count(argv) == 1)
			builtin_export_burbuja();
		free(argv);
	}
	return ;
}
