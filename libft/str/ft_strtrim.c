/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:50:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:11:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pt;
	char	*fs1;
	size_t	s1len;

	if (!s1 || !set)
		return (0);
	s1len = ft_strlen(s1);
	fs1 = (char *)s1 + s1len;
	while (s1 < fs1 && ft_strchr(set, *s1))
		s1++;
	while (fs1 >= s1 && ft_strchr(set, *fs1))
		fs1--;
	pt = (char *)ft_calloc(fs1 - s1 + 2, 1);
	if (pt && ft_memcpy(pt, s1, fs1 - s1 + 1))
	{
		return (pt);
	}
	else
		return (0);
}
