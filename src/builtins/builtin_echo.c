/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:27 by icastell          #+#    #+#             */
/*   Updated: 2022/09/04 09:17:32 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_argument(char **argv, size_t k)
{
	ft_putstr_fd(argv[k], 1);
	if (argv[k + 1])
		ft_putchar_fd(' ', 1);
	return ;
}

static size_t	new_line(char **argv, size_t k)
{
	size_t	i;
	size_t	newline;

	newline = 0;
	i = 1;
	while (++i < ft_strlen(argv[k]))
	{
		if (argv[k][i] != 'n')
		{
			newline = 1;
			print_argument(argv, k);
			break ;
		}
	}
	return (newline);
}

void	builtin_echo(t_command *cmd)
{
	size_t	j;
	size_t	newline;
	char	**argv;

	argv = get_array_from_token_lst(cmd->argv);
	j = 0;
	newline = 1;
	while (argv && argv[++j])
	{
		if ((ft_strncmp(argv[j], "-n", 2) == 0) && (j == 1))
		{
			if (ft_strlen(argv[j]) >= 2)
				newline = new_line(argv, j);
		}
		else
			print_argument(argv, j);
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	ft_array_free(argv);
	return ;
}
