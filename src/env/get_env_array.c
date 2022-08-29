/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:50:40 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/22 21:28:09 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_env_array(void)
{
	t_env_node	*node;
	char		**env;
	char		**tmp;
	char		*tmp2;

	env = ft_calloc(get_env_size() + 1, sizeof(char *));
	tmp = env;
	node = gs_info()->env;
	while (node)
	{
		tmp2 = ft_strjoin(node->name, "=");
		*tmp = ft_strjoin(tmp2, node->value);
		free(tmp2);
		tmp++;
		node = node->next;
	}
	return (env);
}
