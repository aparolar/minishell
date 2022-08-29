/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:34:05 by icastell          #+#    #+#             */
/*   Updated: 2022/06/20 16:55:35 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(t_command *cmd)
{
	t_env_node	*node;

	node = gs_info()->env;
	while (node)
	{
		ft_putstr_fd(node->name, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putendl_fd(node->value, STDOUT_FILENO);
		node = node->next;
	}
	return ;
}
