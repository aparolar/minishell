/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:18:15 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 20:05:56 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*lexer(void)
{
	t_list	*head;
	t_list	*cmd_head;

	head = gs_info()->tk;
	if (!check_consistence(&head))
	{
		print_error(NULL, NULL, "syntax error near unexpected token");
		return (NULL);
	}
	else if (ft_lstsize(head) == 1 && !((t_token *)head->content)->start)
		return (NULL);
	cmd_head = get_commands(head);
	expanse_vars(cmd_head, gs_info()->env);
	return (cmd_head);
}
