/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:37:32 by icastell          #+#    #+#             */
/*   Updated: 2022/07/02 20:43:53 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_env_size(void)
{
	t_env_node	*node;
	int			i;

	node = gs_info()->env;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}
