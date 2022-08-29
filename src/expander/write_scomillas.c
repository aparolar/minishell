/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_scomillas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:33:49 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:43:17 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	write_scomillas_exit(t_expansion *exp)
{
	fill(exp);
	exp->aux = ft_strjoin_v2(exp->aux, exp->value);
	free(exp->value);
	return ;
}

void	write_scomillas(t_expansion *exp)
{
	int		i;
	int		j;

	i = exp->index;
	j = 0;
	while (exp->str[i + j] != '\'')
	{
		if ((exp->dcomillas == 1) && (exp->str[i + j] == '\"'))
		{
			exp->dcomillas = 0;
			exp->quotes.d_index = 0;
		}
		j++;
	}
	exp->value = ft_substr(exp->str, i, j);
	write_scomillas_exit(exp);
	exp->index = i + j;
	return ;
}
