/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_expanse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:03:50 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/27 13:28:41 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*do_expanse(char *str, char *start, char *end)
{
	char	*tmp;
	char	*var;
	char	*value;

	if (!(end - start))
		return (str);
	var = ft_substr(start, 0, end - start);
	value = get_env_var(var + 1);
	tmp = str;
	if (value)
		str = ft_strreplace(tmp, var, value);
	else
		str = ft_strrem(str, start - str, end - start);
	free(var);
	return (str);
}
