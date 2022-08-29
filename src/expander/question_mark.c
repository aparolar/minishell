/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question_mark.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:14:30 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:42:11 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	question_mark(t_expansion *exp)
{
	char	*str;

	str = exp->dquote.str;
	get_name_var_env(exp);
	exp->dquote.value = ft_itoa(gs_info()->exit_status);
	exp->dquote.str = ft_strreplace(exp->dquote.str, exp->dquote.name_var_env,
			exp->dquote.value);
	free(str);
	if (exp->dquote.value)
		free(exp->dquote.value);
	return ;
}
