/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:35:45 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:09:39 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstiter_count(t_list *lst, int (*f)(void *))
{
	int	ret;

	ret = 0;
	if (lst && f)
	{
		while (lst)
		{
			if (f(lst->content))
				ret++;
			lst = lst->next;
		}
	}
	return (ret);
}
