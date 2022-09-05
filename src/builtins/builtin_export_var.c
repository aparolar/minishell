/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:58:49 by icastell          #+#    #+#             */
/*   Updated: 2022/09/05 18:30:07 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*static void	print_error(char *str)
{
	ft_putstr_fd("export: '", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_putstr_fd("': not a valid identifier", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
*/
static void	insert_var(t_export *export)
{
	int				i;
	t_key_value_var	var_env;

	i = 1;
	while (export->str[i] != (void *)0)
	{
		get_name_var_to_export(export, export->str[i]);
		if (export->check == 0)
			print_error("export", export->str[i], NOT_VALID_IDENTIFIER);
		else if (export->check == 1)
		{
			get_value_var_to_export(export, export->str[i]);
			if (get_env_var(export->name) == (void *)0)
			{
				var_env.key = ft_strdup(export->name);
				var_env.value = ft_strdup(export->aux);
				add_env_entry(&var_env);
				free(export->aux);
			}
			else
				set_env_var(export->name, export->aux);
		}
		free(export->name);
		i++;
	}
}

void	builtin_export_var(char **argv)
{
	t_export	export;

	export.str = argv;
	export.index = 0;
	export.check = 0;
	insert_var(&export);
}
