/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:06:01 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 12:14:44 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_env_entry(char *key)
{
	t_env_node	*prev;
	t_env_node	*node;

	prev = NULL;
	node = gs_info()->env;
	while (node)
	{
		if (ft_strcmp(node->name, key))
		{
			if (prev && node->next)
				prev->next = node->next;
			else if (prev && !node->next)
				prev->next = NULL;
			if (!prev && !node->next)
				gs_info()->env = NULL;
			free(node->name);
			free(node->value);
			free(node);
			break ;
		}
		prev = node;
		node = node->next;
	}	
}
