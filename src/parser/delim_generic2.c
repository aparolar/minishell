/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_generic2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:53:45 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 10:53:57 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delim_generic2(t_list **token_lst, char *str, int sflag, int dflag)
{
	t_token	*token;

	token = (*token_lst)->content;
	if (!(token->flags & TOKEN_EMPTY || token->flags & sflag)
		|| token->flags & dflag)
		insert_token_and_move(token_lst, sflag);
	else
	{
		set_token_flag_if(token, dflag, sflag);
		set_token_flag_isempty(token, sflag);
	}
	*str = '\0';
}
