/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:15:13 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 14:54:17 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_token_quotes(t_token *token, char chr)
{
	if ((!(token->flags & TOKEN_QUOTES) || token->flags & TOKEN_SQUOTE)
		&& chr == '\'')
	{
		if (token->flags & TOKEN_SQUOTE)
			token->flags |= TOKEN_CSQUOTE;
		token->flags ^= TOKEN_SQUOTE;
	}
	if ((!(token->flags & TOKEN_QUOTES) || token->flags & TOKEN_DQUOTE)
		&& chr == '"')
	{
		if (token->flags & TOKEN_DQUOTE)
			token->flags |= TOKEN_CDQUOTE;
		token->flags ^= TOKEN_DQUOTE;
	}
}
