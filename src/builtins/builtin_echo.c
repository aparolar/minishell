/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:27 by icastell          #+#    #+#             */
/*   Updated: 2022/06/13 10:01:40 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(t_command *cmd)
{
	size_t	i;
	size_t	newline;
	char	**argv;

	argv = get_array_from_token_lst(cmd->argv);
	i = 0;
	newline = 1;
	while (argv && argv[++i])
	{
		if (ft_strncmp(argv[i], "-n", 3) == 0)
			newline = 0;
		else
		{
			ft_putstr_fd(argv[i], 1);
			if (argv[i + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	ft_array_free(argv);
	return ;
}
