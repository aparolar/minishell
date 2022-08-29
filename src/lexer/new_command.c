/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:22:33 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/05 11:12:25 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*new_command(void)
{
	t_command	*node;

	node = ft_calloc(1, sizeof(t_command));
	if (node)
	{
		node->argv = NULL;
		node->redir = NULL;
		node->fd_in = -1;
		node->fd_out = -1;
		node->pipe_side = -1;
	}
	return (node);
}
