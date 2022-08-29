/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:02:17 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 11:02:32 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_token_start(t_token *token, char *str)
{
	if (token->flags & TOKEN_EMPTY)
	{
		token->start = str;
		token->flags ^= TOKEN_EMPTY;
		token->flags |= TOKEN_TEXT;
	}
}
