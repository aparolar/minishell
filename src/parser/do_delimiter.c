/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_delimiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:13:03 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/21 04:01:20 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_delimiter(t_list **token_lst, t_list *delim_lst, char **str)
{
	t_delim	*delim;

	while (delim_lst)
	{
		delim = delim_lst->content;
		if (delim->chr == **str)
		{
			delim->f(token_lst, *str);
			(*str)++;
			return ;
		}
		delim_lst = delim_lst->next;
	}
	delim_default(token_lst, str);
}
