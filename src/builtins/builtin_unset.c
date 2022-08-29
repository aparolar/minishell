/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:21:49 by icastell          #+#    #+#             */
/*   Updated: 2022/06/20 18:06:56 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pre_unset(t_command *cmd)
{
	char		**argv;
	t_builtin	builtin;

	errno = 0;
	argv = get_array_from_token_lst(cmd->argv);
	if ((argv) && (ft_array_count(argv)) > 0)
	{
		if ((argv[1]) && get_env_var(argv[1]))
			remove_env_entry(argv[1]);
		free(argv);
	}
	return ;
}

void	builtin_unset(t_command *cmd)
{
	return ;
}
