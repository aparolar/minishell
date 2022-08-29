/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:29:14 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:41:57 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_name_var_env(char *name_var_env)
{
	int	i;
	int	is_alnum;

	i = 1;
	is_alnum = 1;
	if ((ft_isalpha(name_var_env[i]) == 1) || (name_var_env[i] == '_')
		|| (name_var_env[i] == '?'))
	{
		i++;
		while (name_var_env[i] != '\0')
		{
			if ((ft_isalnum(name_var_env[i]) == 0) && (name_var_env[i] != '_'))
			{
				is_alnum = 0;
				break ;
			}
			i++;
		}
	}
	return (is_alnum);
}

void	get_var_env(t_expansion *exp)
{
	char	*name_var_env;

	name_var_env = NULL;
	if (check_name_var_env(exp->dquote.name_var_env) == 1)
	{
		name_var_env = ft_substr(exp->dquote.name_var_env, 1,
				ft_strlen(exp->dquote.name_var_env) - 1);
		exp->dquote.value = get_env_var(name_var_env);
	}
	free(name_var_env);
	return ;
}
