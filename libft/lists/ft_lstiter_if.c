/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:10:20 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:09:50 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter_if(t_list *lst, void *content,
		void (*f)(void *), int (*cmp)(void *, void *))
{
	if (lst)
	{
		if (!(*cmp)(lst->content, content))
			f(lst->content);
		lst = lst->next;
	}
}
