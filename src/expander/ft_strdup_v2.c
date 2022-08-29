/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:10:46 by icastell          #+#    #+#             */
/*   Updated: 2022/06/08 09:32:23 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_strdup() function allocates sufficient memory for a copy of the
string str, does the copy, and returns a pointer to it. The pointer may
subsequently be used as an argument to the function free. If insufficient
memory is available, NULL is returned and errno is set to ENOMEM.*/

#include "../minishell.h"

char	*ft_strdup_v2(char *str)
{
	size_t	longitud;
	int		i;
	char	*ptr;

	i = 0;
	longitud = ft_strlen(str);
	ptr = malloc(longitud + 1);
	if (!ptr)
		return (NULL);
	else
	{
		while (str[i] != '\0')
		{
			ptr[i] = str[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
