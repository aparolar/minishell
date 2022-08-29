/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_without_comillas.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:51:30 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:43:25 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	write_without_comillas_exit(t_expansion *exp)
{
	exp->aux = ft_strjoin_v2(exp->aux, exp->value);
	free(exp->value);
	return ;
}

void	write_without_comillas(t_expansion *exp)
{
	int	i;
	int	j;
	int	k;

	i = exp->index;
	j = 0;
	k = 0;
	while ((exp->str[i + j] != '\"') && (exp->str[i + j] != '\'')
		&& (exp->str[i + j] != '\0'))
	{
		if ((exp->str[i + j] == '$') && ((exp->str[i + j + 1] == '\'')
				|| (exp->str[i + j + 1] == '\"')))
		{
			if ((i + j) == 0)
				k = 1;
			else if (((i + j) > 0) && (exp->str[i + j - 1] != '$'))
				k++;
		}	
		j++;
	}
	exp->value = ft_substr(exp->str, i, j - k);
	copy_to_expand(exp);
	write_without_comillas_exit(exp);
	exp->index = i + j;
	return ;
}
