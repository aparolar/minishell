/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:30:47 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:11:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrem(const char *s, size_t start, size_t len)
{
	char	*st;
	char	*st2;
	char	*s1;

	s1 = (char *)s;
	st = 0;
	if (start < ft_strlen(s))
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		st = ft_calloc(ft_strlen(s) - len + 1, sizeof(char));
		st2 = st;
		while (*s1)
		{
			if ((size_t)(s1 - s) < start || (size_t)(s1 - s) > start + len - 1)
			{
				st[st2 - st] = *s1;
				st2++;
			}
			s1++;
		}
	}
	else
		st = ft_calloc(1, sizeof(char));
	return (st);
}
