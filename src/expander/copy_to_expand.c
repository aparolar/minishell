/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_to_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:31:10 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:41:22 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	replace_alpha(t_expansion *exp, int i)
{
	var_env_replace_alpha(exp);
	if (ft_strlen(exp->dquote.name_var_env)
		>= ft_strlen(exp->dquote.value))
		i += ft_strlen(exp->dquote.value) - 1;
	else
		i += ft_strlen(exp->dquote.name_var_env) - 1;
	return (i);
}

void	copy_to_expand_exit(t_expansion *exp)
{
	free(exp->value);
	exp->value = ft_strdup(exp->dquote.str);
	free(exp->dquote.str);
	return ;
}

void	copy_to_expand(t_expansion *exp)
{
	int	i;

	i = 0;
	exp->dquote.str = ft_strdup(exp->value);
	while ((*exp->dquote.str) && (exp->dquote.str[i] != '\0'))
	{
		exp->dquote.name_var_env = NULL;
		if (exp->dquote.str[i] == '$')
		{
			exp->dquote.index = i;
			if ((ft_isalpha(exp->dquote.str[i + 1]) == 1)
				|| (exp->dquote.str[i + 1] == '_'))
				i = replace_alpha(exp, i);
			else if (ft_isdigit(exp->dquote.str[i + 1]) == 1)
				var_env_replace_digit(exp);
			else if (exp->dquote.str[i + 1] == '?')
				question_mark(exp);
			if (exp->dquote.name_var_env)
				free(exp->dquote.name_var_env);
		}
		i++;
	}
	copy_to_expand_exit(exp);
}
