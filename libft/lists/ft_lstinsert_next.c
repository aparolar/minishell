/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:28:48 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/02 09:32:57 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstinsert_next(t_list *lst, t_list *new)
{
	if (lst && new)
	{
		new->next = lst->next;
		lst->next = new;
	}
}
