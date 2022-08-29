/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:47:53 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/29 14:12:49 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_var(char *key)
{
	t_env_node	*node;

	if (!key)
		return (0);
	node = gs_info()->env;
	while (node)
	{
		if (ft_strcmp(key, node->name))
			return (node->value);
		node = node->next;
	}
	return (0);
}
