/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_command_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:26:51 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/11 11:09:06 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*new_command_node(void)
{
	t_list	*node;

	node = ft_lstnew(new_command());
	((t_command *)node->content)->node = node;
	return (node);
}
