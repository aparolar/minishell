/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:03:24 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/26 21:49:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	show_error(t_command *cmd, char *filename)
{
	if (cmd->argv)
		filename = ((t_token *)cmd->argv->content)->start;
	if (errno == EACCES)
		err_permission_deny(cmd, filename);
	else if (errno == ENOENT)
		err_file_dir_not_found(cmd, filename);
	else if (errno == ENOTDIR)
		err_permission_deny(cmd, filename);
	else
		printf("error\n");
	errno = 0;
}
