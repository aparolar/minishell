/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:09:40 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/02 17:03:20 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*get_tokens(char *str)
{
	t_list	*token_lst;
	t_list	*head_token_lst;
	t_list	*delim_lst;

	head_token_lst = ft_lstnew(new_token(TOKEN_EMPTY));
	token_lst = head_token_lst;
	delim_lst = gs_info()->delim;
	while (*str)
		do_delimiter(&token_lst, delim_lst, &str);
	return (head_token_lst);
}
