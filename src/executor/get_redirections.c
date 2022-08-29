/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:36:52 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/27 12:07:42 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	get_dinput(t_command *cmd, t_token *token)
{
	close(cmd->fd_in);
	cmd->fd_in = open("/tmp/.hd_tmp", O_RDONLY, 0666);
}

static void	get_sinput(t_command *cmd, t_token *token)
{
	close(cmd->fd_in);
	cmd->fd_in = open(token->start, O_RDONLY);
	check_redirecction_errors(cmd->fd_in, token->start);
}

static void	get_doutput(t_command *cmd, t_token *token)
{
	close(cmd->fd_out);
	cmd->fd_out = open(token->start, O_RDWR | O_APPEND | O_CREAT, 0666);
	check_redirecction_errors(cmd->fd_out, token->start);
}

static void	get_soutput(t_command *cmd, t_token *token)
{
	close(cmd->fd_out);
	cmd->fd_out = open(token->start, O_RDWR | O_TRUNC | O_CREAT, 0666);
	check_redirecction_errors(cmd->fd_out, token->start);
}

void	get_redirections(t_command *cmd)
{
	t_token	*token;

	if (ft_lstsize(cmd->redir))
	{
		token = cmd->redir->content;
		while (token)
		{
			if (token->flags & TOKEN_DINPUT)
				get_dinput(cmd, token);
			else if (token->flags & TOKEN_SINPUT)
				get_sinput(cmd, token);
			else if (token->flags & TOKEN_DOUTPUT)
				get_doutput(cmd, token);
			else if (token->flags & TOKEN_SOUTPUT)
				get_soutput(cmd, token);
			else if (cmd->result)
				exit(29);
			if (token->node->next)
				token = token->node->next->content;
			else
				token = NULL;
		}
	}
}
