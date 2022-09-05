/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_file_dir_not_found.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:06:51 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 18:43:04 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	err_file_dir_not_found1(t_command *cmd, char *filename)
{
	(void)cmd;
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(" -> ", 2);
	ft_putendl_fd(strerror(errno), 2);
}
