/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_replace_alpha.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:38:55 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:42:28 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	var_env_replace_alpha(t_expansion *exp)
{
	char	*str;

	str = exp->dquote.str;
	get_name_var_env(exp);
	get_var_env(exp);
	if (exp->dquote.value)
		exp->dquote.str = ft_strreplace(exp->dquote.str,
				exp->dquote.name_var_env, exp->dquote.value);
	else
		exp->dquote.str = ft_strreplace(exp->dquote.str,
				exp->dquote.name_var_env, "");
	free(str);
	return ;
}
