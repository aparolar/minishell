/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:36:13 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/03 13:12:13 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*new_token_node(int flags)
{
	t_token	*token;
	t_list	*lst_node;

	token = new_token(flags);
	lst_node = ft_lstnew(token);
	token->node = lst_node;
	return (lst_node);
}

//return (ft_lstnew(new_token(flags)));