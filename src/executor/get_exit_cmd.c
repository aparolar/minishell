/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:07:09 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/18 14:59:34 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*get_exit_next_command(t_command *cmd)
{
	t_token		*token;
	t_command	*ret;
	t_command	*start;

	ret = NULL;
	start = cmd;
	token = cmd->argv->content;
	while (cmd)
	{
		if (ft_strcmp(token->start, "exit"))
			ret = cmd;
		if (cmd->node->next)
			cmd = cmd->node->next->content;
		else
			cmd = NULL;
		if (cmd)
			token = cmd->argv->content;
	}
	if (ret && ret->node->next)
		return (ret->node->next->content);
	else if (ret && (!ret->node->next))
		return (cmd);
	return (start);
}
