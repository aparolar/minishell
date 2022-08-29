/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:40:12 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:11:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*p_s;

	p_s = (char *)s;
	len = ft_strlen(s);
	if (!c)
		return (p_s + len);
	if (!len)
		return (NULL);
	while (--len > 0)
	{
		if (p_s[len] == (char)c)
			return (p_s + len);
		else if (!(len - 1) && p_s[0] == (char)c)
			return (p_s);
	}
	return (NULL);
}
