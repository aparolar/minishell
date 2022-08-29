/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_to_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:51:56 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:42:21 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	num_quotes(int quotes)
{
	quotes++;
	if (quotes == 2)
		quotes = 0;
	return (quotes);
}

static void	quotes_to_expansion(t_expansion *exp)
{
	int	i;

	i = exp->index;
	if (exp->str[i] == '\'')
	{
		exp->scomillas = num_quotes(exp->scomillas);
		if (exp->scomillas == 0)
			exp->quotes.s_index = 0;
		else
			exp->quotes.s_index = i;
	}
	else if (exp->str[i] == '\"')
	{
		exp->dcomillas = num_quotes(exp->dcomillas);
		if (exp->dcomillas == 0)
			exp->quotes.d_index = 0;
		else
			exp->quotes.d_index = i;
	}
	exp->index++;
	return ;
}

void	quotes(t_expansion *exp)
{
	quotes_to_expansion(exp);
	if (exp->scomillas == 1)
		write_scomillas(exp);
	else if (exp->dcomillas == 1)
		write_dcomillas(exp);
	return ;
}
