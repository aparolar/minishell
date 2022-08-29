/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:31:49 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 12:01:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_node	*add_env_entry(t_key_value_var *kv)
{
	t_env_node	*node;
	t_env_node	*new;

	node = gs_info()->env;
	while (node && node->next)
		node = node->next;
	new = ft_calloc(1, sizeof(t_env_node));
	if (node)
		node->next = new;
	else
	{
		node = new;
		gs_info()->env = new;
	}
	new->name = kv->key;
	new->value = kv->value;
	return (new);
}
