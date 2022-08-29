/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_var_to_export.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:07:59 by icastell          #+#    #+#             */
/*   Updated: 2022/06/28 17:32:35 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_name_var_to_export(t_export *export)
{
	if ((ft_isalpha(export->name[0]) == 0) && (export->name[0] != '_'))
		export->check = 0;
	else if ((ft_isalpha(export->name[0]) == 1) || (export->name[0] == '_'))
		export->check = 1;
	return ;
}
