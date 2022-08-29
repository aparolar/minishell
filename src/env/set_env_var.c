/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:48:48 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 11:49:01 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_env_var(char *key, char *value)
{
	t_env_node	*node;

	node = gs_info()->env;
	while (node)
	{
		if (ft_strcmp(key, node->name))
		{
			free(node->value);
			node->value = value;
			break ;
		}
		node = node->next;
	}	
}
