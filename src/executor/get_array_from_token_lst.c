/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_from_token_lst.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:43:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/03 19:02:31 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_array_from_token_lst(t_list *token_lst)
{
	int		array_len;
	char	**array;
	char	**tmp;

	array_len = ft_lstsize(token_lst) + 1;
	array = malloc(array_len * sizeof(char *));
	tmp = array;
	array[array_len - 1] = NULL;
	while (token_lst)
	{
		*tmp = ((t_token *)token_lst->content)->start;
		tmp++;
		token_lst = token_lst->next;
	}
	return (array);
}
