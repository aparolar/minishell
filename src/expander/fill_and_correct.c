/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:15:10 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:41:30 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill(t_expansion *exp)
{
	int	i;

	i = 0;
	while (exp->value[i] != '\0')
	{
		if (exp->value[i] == ' ')
			exp->value[i] = '\1';
		i++;
	}
	return ;
}

void	correction(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\1')
			str[i] = ' ';
		i++;
	}
	return ;
}
