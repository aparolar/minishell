/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:42:08 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/24 12:42:32 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter_var(t_list *lst, void (*f)(void *, void **), void **var)
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content, var);
			lst = lst->next;
		}
	}
}
