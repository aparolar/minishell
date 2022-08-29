/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_consistence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:11:55 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/21 14:16:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	merge_redirs(void *c_before, void *content, void *c_after)
{
	t_token	*token;
	t_token	*before;
	int		is_sor;

	token = content;
	before = c_before;
	is_sor = 0;
	if (before)
	{
		is_sor = before->flags & TOKEN_SOR;
		if (before->flags & TOKEN_IO && token->flags & TOKEN_TEXT
			&& !(before->flags & TOKEN_LOCKED))
		{
			token->flags |= (before->flags & TOKEN_IO) | TOKEN_LOCKED;
			token->flags ^= TOKEN_EMPTY;
			if (!is_sor)
				before->flags = TOKEN_EMPTY;
			else
				before->flags = is_sor;
		}
	}
	return (0);
}

static int	check_bad_format(void *c_before, void *content, void *c_after)
{
	t_token	*token;
	t_token	*before;
	t_token	*after;
	int		cond;

	cond = TOKEN_IO | TOKEN_SOR;
	token = content;
	before = c_before;
	after = c_after;
	if ((!before && token->flags & TOKEN_SOR)
		|| (!after && token->flags & TOKEN_SOR))
		return (1);
	if (token->flags & TOKEN_QUOTES)
		return (1);
	else if (before && before->flags & TOKEN_SOR && token->flags & TOKEN_SOR)
		return (1);
	else if (token->flags & TOKEN_IO && !(token->flags & TOKEN_TEXT))
		return (1);
	else if (token->flags
		& (TOKEN_OPERATOR & ~(cond | TOKEN_TEXT | TOKEN_EMPTY)))
		return (1);
	return (0);
}

int	check_consistence(t_list **command_lst)
{
	t_list	*token_lst;
	t_list	*split;

	token_lst = gs_info()->tk;
	ft_lstiter_bpa_if(token_lst, merge_redirs);
	return (ft_lstiter_bpa_if(token_lst, check_bad_format));
}
