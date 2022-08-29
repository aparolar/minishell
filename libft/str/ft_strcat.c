/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:08:43 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:11:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(const char *s1, const char *s2)
{
	char	*ret;
	char	*ps1;
	char	*ps2;

	if (s1 && s2)
	{
		ps1 = (char *)s1;
		ps2 = (char *)s2;
		ret = ft_calloc(ft_strlen(ps1) + ft_strlen(ps2) + 1, sizeof(char));
		if (ret)
		{
			while (*ps1)
			{
				ret[ps1 - s1] = *ps1;
				ps1++;
			}
			while (*ps2)
			{
				ret[(ps1 - s1) + (ps2 - s2)] = *ps2;
				ps2++;
			}
			return (ret);
		}
	}
	return (0);
}
