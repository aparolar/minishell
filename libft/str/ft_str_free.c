/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:50:31 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/27 16:51:24 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_str_free(char **new, char **old)
{
	if (!*old && !*new)
		return (NULL);
	if (!*old && *new)
		return (*new);
	if (!*new && *old)
		return (*old);
	if (*new != *old)
		free(*old);
	*old = NULL;
	return (*new);
}
