/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:39:27 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 10:17:20 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(t_command *cmd)
{
	ft_putstr_fd(get_env_var("PWD"), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
