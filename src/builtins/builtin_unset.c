/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:21:49 by icastell          #+#    #+#             */
/*   Updated: 2022/09/05 12:19:35 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pre_unset(t_command *cmd)
{
	char	**argv;
	size_t	i;
	size_t	count;

	errno = 0;
	i = 1;
	argv = get_array_from_token_lst(cmd->argv);
	count = ft_array_count(argv);
	if ((argv) && (count > 0))
	{
		while (i < count)
		{
			if ((argv[i]) && get_env_var(argv[i]))
				remove_env_entry(argv[i]);
			i++;
		}
		free(argv);
	}
	return ;
}

void	builtin_unset(t_command *cmd)
{
	(void)cmd;
	return ;
}
