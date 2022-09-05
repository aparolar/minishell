/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_permission_deny.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:29:30 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 18:43:23 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	err_permission_deny1(t_command *cmd, char *filename)
{
	(void)cmd;
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(" -> ", 2);
	ft_putendl_fd(strerror(errno), 2);
}
