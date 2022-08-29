/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expanded_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:51:01 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 09:52:17 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_list	*add_new_subtoken(t_list *token_lst, char *str)
{
	t_list	*new_node;
	t_token	*newtoken;

	new_node = new_token_node(TOKEN_TEXT | TOKEN_EXPANDED);
	newtoken = new_node->content;
	newtoken->start = str;
	ft_lstinsert_next(token_lst, new_node);
	return (new_node);
}

void	split_expanded_token(t_list *token_lst, char **arr)
{
	char	*tmp;
	char	**next;

	tmp = ((t_token *)token_lst->content)->start;
	next = arr;
	free(((t_token *)token_lst->content)->start);
	((t_token *)token_lst->content)->start = *next;
	if (ft_array_count(arr) > 1)
	{
		next++;
		while (*next)
		{
			token_lst = add_new_subtoken(token_lst, *next);
			next++;
		}
	}
	free(arr);
	((t_token *)token_lst->content)->flags |= TOKEN_EXPANDED;
}
