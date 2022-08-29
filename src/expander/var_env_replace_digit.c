/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_replace_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:14 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:43:04 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	var_env_replace_digit(t_expansion *exp)
{
	char	*aux;

	get_name_var_env(exp);
	aux = exp->dquote.str;
	exp->dquote.str = ft_strreplace(exp->dquote.str,
			exp->dquote.name_var_env, "");
	free(aux);
	return ;
}
