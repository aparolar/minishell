/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:39:27 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/01 17:09:44 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(t_command *cmd)
{
	(void)cmd;
	ft_putstr_fd(get_env_var("PWD"), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
