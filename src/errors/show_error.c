/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:03:24 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 18:52:41 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
void	show_error(t_command *cmd, char *filename)
{
	if (cmd->argv)
		filename = ((t_token *)cmd->argv->content)->start;
	if (errno == EACCES)
		print_error("", filename, strerror(errno));
	else if (errno == ENOENT)
		print_error(cmd, filename, strerror(errno));
	else if (errno == ENOTDIR)
		print_error(cmd, filename, strerror(errno));
	else
		printf("error\n");
	errno = 0;
}
*/