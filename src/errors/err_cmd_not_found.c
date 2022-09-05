/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cmd_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:06:51 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 18:43:18 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	err_cmd_not_found1(t_command *cmd)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(((t_token *)cmd->argv->content)->start, 2);
	ft_putstr_fd(" -> ", 2);
	ft_putendl_fd(strerror(errno), 2);
}
