/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_generic1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:46:34 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 10:55:05 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delim_generic1(t_list **token_lst, char *str, int sflag)
{
	t_token	*token;

	token = (*token_lst)->content;
	if (!(token->flags & TOKEN_EMPTY))
		insert_token_and_move(token_lst, sflag);
	else
		set_token_flag_isempty(token, sflag);
	*str = '\0';
}
