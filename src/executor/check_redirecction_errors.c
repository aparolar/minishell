/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirecction_errors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:24:50 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/14 13:27:18 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_redirecction_errors(int fd, char *filename)
{
	if (fd == -1)
	{
		if (errno == EACCES)
			err_permission_deny(NULL, filename);
		else
			err_file_dir_not_found(NULL, filename);
		exit(1);
	}
}
