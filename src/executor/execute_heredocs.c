/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:58:56 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/30 18:55:36 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_heredocs(t_command *cmd)
{
	t_token	*token;

	token = NULL;
	if (cmd->redir)
		token = cmd->redir->content;
	while (token && WEXITSTATUS(gs_info()->exit_status) != 130)
	{
		if (token->flags & TOKEN_DINPUT)
			get_heredoc(cmd, token);
		if (token->node->next)
			token = token->node->next->content;
		else
			token = NULL;
	}
}
