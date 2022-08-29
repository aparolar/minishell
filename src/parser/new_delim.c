/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_delim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:58:03 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/12 11:03:13 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_delim	*new_delim(char chr, void (*f)(t_list **, char *))
{
	t_delim	*node;

	node = malloc(sizeof(t_delim));
	if (node)
	{
		node->chr = chr;
		node->f = f;
	}
	return (node);
}
