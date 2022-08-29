/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:24:35 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/12 12:21:17 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delim_space(t_list **token_lst, char *str)
{
	t_token	*token;

	token = (*token_lst)->content;
	if (token->flags & TOKEN_EMPTY)
		return ;
	insert_token_and_move(token_lst, TOKEN_EMPTY);
	*str = 0;
}
