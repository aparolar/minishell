/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirecction_errors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:24:50 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 19:00:48 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_redirecction_errors(int fd, char *filename)
{
	if (fd == -1)
	{
		if (errno == EACCES)
			print_error(filename, NULL, strerror(errno));
		else
			print_error(filename, NULL, strerror(errno));
		exit(1);
	}
}
