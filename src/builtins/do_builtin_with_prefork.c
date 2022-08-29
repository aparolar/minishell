/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_with_prefork.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:56:42 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/18 18:27:59 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_builtin_with_prefork(int fd_in, t_command *cmd,
			void (*pf)(t_command *cmd),	void (*f)(t_command *cmd))
{
	if (pf)
		pf(cmd);
	do_builtin_fork(fd_in, cmd, f);
}
