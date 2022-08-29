/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_var_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:37:18 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:41:49 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	name_delimiter(int c)
{
	int	alnum;

	if (((c < 48) || ((c >= 58) && (c < 65)) || ((c >= 91) && (c <= 96))
			|| (c > 122)) && (c != 95))
		alnum = 0;
	else
		alnum = 1;
	return (alnum);
}

void	get_name_var_env(t_expansion *exp)
{
	int	i;
	int	j;

	i = exp->dquote.index + 1;
	j = 0;
	if ((ft_isalpha(exp->dquote.str[i + j]) == 1)
		|| (exp->dquote.str[i + j] == '_'))
	{
		while (name_delimiter(exp->dquote.str[i + j]) == 1)
			j++;
		exp->dquote.name_var_env = ft_substr(exp->dquote.str, i - 1, j + 1);
	}
	else if ((ft_isdigit(exp->dquote.str[i + j]) == 1)
		|| (exp->dquote.str[i + j] == '?'))
		exp->dquote.name_var_env = ft_substr(exp->dquote.str, i - 1, 2);
	return ;
}
