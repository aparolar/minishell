/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:08:27 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/21 14:19:56 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	add_redir(t_command *cmd, t_list *new)
{
	if (!cmd->redir)
		cmd->redir = new;
	else
		ft_lstadd_back(&cmd->redir, new);
}

static void	add_argv(t_command *cmd, t_list *new)
{
	if (!cmd->argv)
		cmd->argv = new;
	else
		ft_lstadd_back(&cmd->argv, new);
}

static void	search_redirs(void *content)
{
	t_token		*token;
	t_list		*cmd_lst;
	t_command	*cmd;
	t_list		*new;
	t_token		*new_tkn;

	cmd_lst = ft_lstlast(gs_info()->cmd_lst);
	cmd = cmd_lst->content;
	token = content;
	if ((token->flags & TOKEN_IO) || (token->flags & TOKEN_TEXT))
	{
		new = new_token_node(token->flags);
		new_tkn = new->content;
		new_tkn->start = ft_strdup(token->start);
		if (token->flags & TOKEN_IO)
			add_redir(cmd, new);
		else
			add_argv(cmd, new);
	}
	if (token->flags & TOKEN_SOR)
		ft_lstadd_back(&cmd_lst, new_command_node());
}

t_list	*get_commands(t_list *tokens_lst)
{
	gs_info()->cmd_lst = new_command_node();
	ft_lstiter(tokens_lst, search_redirs);
	return (gs_info()->cmd_lst);
}
