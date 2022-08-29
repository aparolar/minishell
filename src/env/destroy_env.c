/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:57:07 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 11:57:18 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	destroy_env(void)
{
	t_env_node	*node;
	t_env_node	*tmp;

	node = gs_info()->env;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
}
