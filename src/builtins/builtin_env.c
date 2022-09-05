/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:34:05 by icastell          #+#    #+#             */
/*   Updated: 2022/09/05 18:36:40 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(t_command *cmd)
{
	t_env_node	*node;

	(void)cmd;
	node = gs_info()->env;
	while (node)
	{
		if (*node->value != '\1')
		{
			ft_putstr_fd(node->name, STDOUT_FILENO);
			ft_putchar_fd('=', STDOUT_FILENO);
			ft_putendl_fd(node->value, STDOUT_FILENO);
		}
		node = node->next;
	}
	return ;
}
