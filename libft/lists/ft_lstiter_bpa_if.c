/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bpa_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:11:45 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 14:27:11 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	*get_content(t_list *lst)
{
	if (lst)
		return (lst->content);
	return (NULL);
}

int	ft_lstiter_bpa_if(t_list *lst, int (*f)(void *, void *, void *))
{
	t_list	*before;
	t_list	*after;

	if (!lst || !f)
		return (0);
	before = NULL;
	while (lst)
	{
		after = lst->next;
		if (f(get_content(before), get_content(lst), get_content(after)))
			return (0);
		before = lst;
		lst = lst->next;
	}
	return (1);
}
