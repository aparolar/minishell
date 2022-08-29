/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:39:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:11:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned int	ft_find_chars(char *str, char c)
{
	unsigned int	len;

	len = 1;
	while (*str)
	{
		if (*str == c || !*(str + 1))
			if (*(str + 1) != c)
				len++;
		str++;
	}
	return (len);
}

static char	**ft_get_split(char **split, char *s, char c)
{
	int		i;
	char	*s2;
	char	*s1;

	s1 = s;
	s2 = s1;
	i = 0;
	while (*s1)
	{
		while (*s1 == c)
			s1++;
		s2 = s1;
		while (*s2 && *s2 != c)
			s2++;
		if (s1 == s2)
			break ;
		split[i] = ft_calloc((s2 - s1 + 1), sizeof(char));
		ft_memcpy(split[i], s1, s2 - s1);
		s1 = s2;
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	maxi;
	char			**split;
	char			*s1;

	if (!s)
		return (0);
	s1 = (char *)s;
	maxi = ft_find_chars(s1, c);
	if (!maxi)
		return (0);
	split = ft_calloc(maxi, sizeof(char *));
	if (!split)
		return (0);
	return (ft_get_split(split, (char *)s, c));
}
