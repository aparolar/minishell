/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_controlled.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:48:33 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/19 10:08:46 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_controlled(int status)
{
	free(gs_info()->cmd_str);
	free_command_lst(&gs_info()->cmd_lst);
	ft_lstclear(&gs_info()->tk, free);
	clean_all();
	exit(status);
}
