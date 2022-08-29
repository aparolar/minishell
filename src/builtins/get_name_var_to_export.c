/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_var_to_export.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:40:16 by icastell          #+#    #+#             */
/*   Updated: 2022/06/28 17:34:31 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_name_var_to_export(t_export *export, char *str)
{
	int	i;

	i = 0;
	export->index = get_index(str, '=');
	if (export->index == 0)
		export->name = ft_substr(str, 0, ft_strlen(str));
	else if (export->index > 0)
		export->name = ft_substr(str, 0, export->index);
	check_name_var_to_export(export);
	return ;
}
