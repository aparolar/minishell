/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:01:41 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/26 11:01:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_new_token(void *content)
{
	free(((t_token *)content)->start);
	free(content);
}

static void	free_command_node(void *content)
{
	t_command	*command;

	command = content;
	ft_lstclear(&command->argv, free_new_token);
	ft_lstclear(&command->redir, free_new_token);
	free(content);
}

void	free_command_lst(t_list **cmd_lst)
{
	ft_lstclear(cmd_lst, free_command_node);
	free(*cmd_lst);
	*cmd_lst = NULL;
}
