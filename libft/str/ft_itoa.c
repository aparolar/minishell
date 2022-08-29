/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:01:26 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:11:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int n)
{
	int		len;
	long	no;
	char	*pr;

	no = n;
	len = ft_intlen(n);
	if (n < 0)
		len++;
	pr = (char *)ft_calloc(len + 1, 1);
	if (!pr)
		return (0);
	while (len > 0)
	{	
		if (n < 0)
			pr[len - 1] = -(n % 10) + 48;
		else
			pr[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (no < 0)
		*pr = '-';
	return (pr);
}
