/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_token_and_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:11:45 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/12 12:13:59 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	insert_token_and_move(t_list **token_lst, int flags)
{
	ft_lstadd_back(token_lst, new_token_node(flags));
	*token_lst = (*token_lst)->next;
}
