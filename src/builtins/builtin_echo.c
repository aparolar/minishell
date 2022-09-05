/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:27 by icastell          #+#    #+#             */
/*   Updated: 2022/09/05 11:27:23 by icastell         ###   ########.fr       */
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
	if (!ft_strncmp(argv[k], "-n", 2))
	{
		while (++i < ft_strlen(argv[k]))
		{
			if (argv[k][i] != 'n')
			{
				newline = 1;
				break ;
			}
		}
	}
	else
		return (1);
	return (newline);
}

static void	print_echo_all_args(char **argv, size_t j)
{
	while (argv && argv[j])
		print_argument(argv, j++);
	return ;
}

void	builtin_echo(t_command *cmd)
{
	_Bool	newline;
	char	**argv;
	size_t	i;

	newline = 1;
	argv = get_array_from_token_lst(cmd->argv);
	i = 1;
	while (!new_line(argv, i))
	{
		newline = 0;
		i++;
	}
	print_echo_all_args(argv, i);
	if (newline)
		ft_putchar_fd('\n', 1);
	ft_array_free(argv);
	return ;
}
