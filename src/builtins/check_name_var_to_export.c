/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_var_to_export.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:07:59 by icastell          #+#    #+#             */
/*   Updated: 2022/09/05 19:57:10 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_name_var_to_export(t_export *export)
{
	int	i;

	i = 0;
	export->check = 0;
	if ((ft_isalpha(export->name[i]) == 1) || (export->name[i] == '_'))
	{
		i++;
		while (export->name[i] != '\0')
		{
			if ((ft_isalnum(export->name[i]) == 0) && (export->name[i] != '_'))
				return ;
			i++;
		}
		export->check = 1;
	}
}
