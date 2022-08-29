/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:34:09 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/26 15:02:13 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*p_s;

	if (!s)
		return (NULL);
	p_s = (char *)s;
	i = 0;
	len = ft_strlen(s);
	if (!c)
		return (p_s + len);
	while (i < len)
	{
		if (p_s[i] == (char)c)
			return (p_s + i);
		i++;
	}
	return (NULL);
}
