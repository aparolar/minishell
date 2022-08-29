/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_with_postfork.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:26:20 by icastell          #+#    #+#             */
/*   Updated: 2022/06/18 18:27:38 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_builtin_with_postfork(int fd_in, t_command *cmd,
			void (*pf)(t_command *cmd),	void (*f)(t_command *cmd))
{
	do_builtin_fork(fd_in, cmd, f);
	if (pf)
		pf(cmd);
}
