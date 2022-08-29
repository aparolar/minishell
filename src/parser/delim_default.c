/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:38:13 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/14 23:39:28 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delim_default(t_list **token_lst, char **str)
{
	t_token	*token;

	token = (*token_lst)->content;
	if (token->flags & TOKEN_OPERATOR)
	{
		insert_token_and_move(token_lst, TOKEN_EMPTY);
		token = (*token_lst)->content;
	}
	set_token_start(token, *str);
	while (**str)
	{
		check_token_quotes(token, **str);
		(*str)++;
		if (!(token->flags & TOKEN_QUOTES))
			break ;
	}
}
