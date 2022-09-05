/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:27 by icastell          #+#    #+#             */
/*   Updated: 2022/09/05 11:17:30 by icastell         ###   ########.fr       */
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

static size_t	printable_arg(char **argv, size_t j)
{
	size_t	i;
	size_t	printable;
	char	*str;

	i = 0;
	printable = 1;
	str = argv[j];
	if (*str == '-')
	{
		str++;
		while (*str)
		{
			if (*str == 'n')
				printable = 0;
			else
			{
				printable = 1;
				break ;
			}
			str++;
		}
	}
	return (printable);
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
		return(1);
	return (newline);
}

static void	print_echo_all_args(char **argv, size_t j)
{
	while (argv && argv[j])
		print_argument(argv, j++);
	return ;
}

static void	print_echo_necesary_args(char **argv, size_t j)
{
	while (argv && argv[j])
	{
		if (printable_arg(argv, j) == 1)
			print_argument(argv, j);
		j++;
	}
	return ;
}

void	builtin_echo(t_command *cmd)
{
	_Bool	newline;
	char	**argv;
	int		i;
	//char	**current;

	newline = 1;
	argv = get_array_from_token_lst(cmd->argv);
	i = 1;
	//current = argv;
	while (!new_line(argv, i))
	{
		newline = 0;
		i++;
	//	++current;
	}
	print_echo_all_args(argv, i);
	if (newline)
		ft_putchar_fd('\n', 1);
	ft_array_free(argv);
}

void	builtin_echo1(t_command *cmd)
{
	size_t	j;
	size_t	newline;
	char	**argv;

	argv = get_array_from_token_lst(cmd->argv);
	j = 0;
	newline = 1;
	if (ft_strncmp(argv[j + 1], "-n", 2) == 0)
	{
		newline = new_line(argv, j + 1);
		if (newline == 1)
			print_echo_all_args(argv, 1);
		else if (newline == 0)
			print_echo_necesary_args(argv, 2);
	}
	else
		print_echo_all_args(argv, 1);
	if (newline)
		ft_putchar_fd('\n', 1);
	ft_array_free(argv);
	return ;
}
