/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:56:41 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/26 12:04:02 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchrs(char *str, char *chrs)
{
	if (!str || !chrs)
		return (NULL);
	while (*chrs)
	{
		str = ft_strchr(str, *chrs);
		if (str)
			break ;
		chrs++;
	}
	return (str);
}
