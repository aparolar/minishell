/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand_vars_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:12:42 by icastell          #+#    #+#             */
/*   Updated: 2022/09/08 20:24:04 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	maybe_expand(t_token *token)
{
	return (ft_strchr(token->start, 34) || ft_strchr(token->start, 39));
}

void	remove_quotes(t_token *token)
{
	char	*aux;
	size_t	i;
	size_t	j;

	aux = ft_calloc(ft_strlen(token->start) - 2, sizeof(char));
	i = 0;
	j = 0;
	while (token->start[i] != '\0')
	{
		if ((token->start[i] != '\'') && (token->start[i] != '\"'))
		{
			aux[j] = token->start[i];
			j++;
		}
		i++;
	}
	aux[i] = '\0';
	token->start = ft_strdup(aux);
	free(aux);
	return ;
	/*aux = ft_strdup(token->start + 1);
	aux[ft_strlen(aux) - 1] = 0;
	token->start = ft_strdup(aux);
	free(aux);
	return ;*/
}
