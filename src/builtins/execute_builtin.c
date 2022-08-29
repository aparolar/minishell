/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:18:46 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/30 11:06:42 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_builtin(int fd_in, char *name, t_command *cmd)
{
	if (ft_strcmp("echo", name))
		do_builtin_fork(fd_in, cmd, builtin_echo);
	else if (ft_strcmp("cd", name))
		do_builtin_with_postfork(fd_in, cmd, builtin_post_cd, builtin_cd);
	else if (ft_strcmp("pwd", name))
		do_builtin_fork(fd_in, cmd, builtin_pwd);
	else if (ft_strcmp("export", name))
		do_builtin_with_prefork(fd_in, cmd, builtin_pre_export, builtin_export);
	else if (ft_strcmp("unset", name))
		do_builtin_with_prefork(fd_in, cmd, builtin_pre_unset, builtin_unset);
	else if (ft_strcmp("env", name))
		do_builtin_fork(fd_in, cmd, builtin_env);
	else if (ft_strcmp("exit", name))
		do_builtin_with_prefork(fd_in, cmd, builtin_pre_exit, builtin_exit);
	return (0);
}
