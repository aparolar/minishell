/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:14:36 by icastell          #+#    #+#             */
/*   Updated: 2022/09/05 18:59:49 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(char *name, char *param, char *msg)
{
	// a cambair minishell por el nombre de argv[0]
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (name)
	{
		ft_putstr_fd(name, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (param)
	{
		ft_putstr_fd("'", STDERR_FILENO);
		ft_putstr_fd(param, STDERR_FILENO);
		ft_putstr_fd("': ", STDERR_FILENO);
	}
	ft_putendl_fd(msg, STDERR_FILENO);
}
