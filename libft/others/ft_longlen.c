/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:24:39 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:11:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_longlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0 || n < 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
