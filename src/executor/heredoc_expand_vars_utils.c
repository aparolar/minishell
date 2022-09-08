/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand_vars_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:12:42 by icastell          #+#    #+#             */
/*   Updated: 2022/09/08 18:16:00 by icastell         ###   ########.fr       */
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

	aux = ft_strdup(token->start + 1);
	aux[ft_strlen(aux) - 1] = 0;
	token->start = ft_strdup(aux);
	free(aux);
	return ;
}
