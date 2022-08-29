/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:07:38 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/26 14:12:11 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*get_next_command(t_command *cmd)
{
	if (cmd && cmd->node->next)
		return (cmd->node->next->content);
	return (NULL);
}
