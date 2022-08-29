/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:01:35 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 12:01:53 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_key_value_var	*get_env_key_value(char *str)
{
	char			*eqpos;
	t_key_value_var	*ret;
	size_t			len;

	len = ft_strlen(str);
	ret = ft_calloc(1, sizeof(t_key_value_var));
	eqpos = ft_strchr(str, '=');
	ret->key = ft_substr(str, 0, eqpos - str);
	ret->value = ft_substr(str, eqpos - str + 1, len - (size_t) eqpos);
	return (ret);
}
