/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:28:41 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/28 07:40:08 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *name)
{
	if (ft_strcmp("echo", name))
		return (1);
	else if (ft_strcmp("cd", name))
		return (1);
	else if (ft_strcmp("pwd", name))
		return (1);
	else if (ft_strcmp("export", name))
		return (1);
	else if (ft_strcmp("unset", name))
		return (1);
	else if (ft_strcmp("env", name))
		return (1);
	else if (ft_strcmp("exit", name))
		return (1);
	return (0);
}
