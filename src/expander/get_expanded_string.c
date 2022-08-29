/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:24:42 by icastell          #+#    #+#             */
/*   Updated: 2022/07/01 13:39:26 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	get_correct_expanded_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		correction(str[i]);
		i++;
	}
	return ;
}

char	**get_expanded_string(t_expansion *exp)
{
	int		i;
	char	**expanded;

	i = exp->index;
	exp->dcomillas = 0;
	exp->scomillas = 0;
	exp->aux = ft_strdup_v2("");
	while (exp->str[i] != '\0')
	{
		exp->index = i;
		if ((exp->str[i] == '\'') || (exp->str[i] == '\"'))
			quotes(exp);
		else
			write_without_comillas(exp);
		i = exp->index;
	}
	expanded = ft_split(exp->aux, ' ');
	free(exp->aux);
	get_correct_expanded_string(expanded);
	return (expanded);
}
