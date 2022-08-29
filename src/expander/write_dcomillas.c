/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dcomillas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:31:10 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:43:10 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	write_dcomillas_exit(t_expansion *exp)
{
	fill(exp);
	exp->aux = ft_strjoin_v2(exp->aux, exp->value);
	free(exp->value);
	return ;
}

void	write_dcomillas(t_expansion *exp)
{
	int	i;
	int	j;

	i = exp->index;
	j = 0;
	while (exp->str[i + j] != '\"')
	{
		if ((exp->scomillas == 1) && (exp->str[i + j] == '\''))
		{
			exp->scomillas = 0;
			exp->quotes.s_index = 0;
		}
		j++;
	}
	exp->value = ft_substr(exp->str, i, j);
	copy_to_expand(exp);
	write_dcomillas_exit(exp);
	exp->index = i + j;
	return ;
}
