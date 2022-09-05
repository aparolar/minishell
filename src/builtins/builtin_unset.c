/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:21:49 by icastell          #+#    #+#             */
/*   Updated: 2022/09/05 18:28:35 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static _Bool	check_var_name(char *argv)
{
	t_export	export;

	export.str = &argv;
	export.index = 0;
	export.check = 0;
	get_name_var_to_export(&export, argv);
	if (argv[ft_strlen(export.name)] == '=')
		export.check = 0;
	return (export.check);
	//check_name_var_to_export(&export);
}

void	builtin_pre_unset(t_command *cmd)
{
	char	**argv;
	size_t	i;
	size_t	count;

	if (ft_lstsize(gs_info()->cmd_lst) > 1)
		return ;
	errno = 0;
	i = 1;
	argv = get_array_from_token_lst(cmd->argv);
	count = ft_array_count(argv);
	if ((argv) && (count > 0))
	{
		while (i < count)
		{
			if (!check_var_name(argv[i]))
				print_error("unset", argv[i], NOT_VALID_IDENTIFIER);
			if ((argv[i]) && get_env_var(argv[i]))
				remove_env_entry(argv[i]);
			i++;
		}
		free(argv);
	}
}


void	builtin_unset(t_command *cmd)
{
	(void)cmd;
	return ;
}
