/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_var_to_export.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:05:46 by icastell          #+#    #+#             */
/*   Updated: 2022/06/28 18:05:12 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_value_var_to_export(t_export *export, char *str)
{
	int	i;

	i = 0;
	export->length = ft_strlen(str);
	if (export->index > 0)
	{
		if (str[export->index + 1] != '\0')
			export->aux = ft_substr(str, export->index + 1,
					export->length - (export->index - 1));
		else
			export->aux = ft_strdup("");
	}
	else if (export->index == 0)
		export->aux = ft_strdup("\1");
	return ;
}
