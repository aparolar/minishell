/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:25:27 by icastell          #+#    #+#             */
/*   Updated: 2022/09/04 19:20:20 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_putstr_fd1(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
	return ;
}

static void	ft_putchar_fd1(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

static int	ft_strncmp1(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	i = 0;
	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	while ((i < n) && (aux1[i] != '\0') && (aux2[i] != '\0'))
	{
		if (aux1[i] != aux2[i])
			return (aux1[i] - aux2[i]);
		i++;
	}
	if (i != n)
		return (aux1[i] - aux2[i]);
	return (0);
}

static void	print_argument(char **argv, size_t k)
{
	//printf("print_arguments %s %p\n", argv[k], argv[k]);
	//printf("%s\n", argv[k]);
	ft_putstr_fd1(argv[k], 1);
	if (argv[k + 1])
		ft_putchar_fd1(' ', 1);
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
	}}
	else
		return(1);
	return (newline);
}

static void	print_echo_all_args(char **argv, size_t j)
{
	while (argv && argv[j++])
		print_argument(argv, j);
	return ;
}

static void	print_echo_necesary_args(char **argv, size_t j)
{
	//printf("print_echo_necesary_args\n");
	while (argv && argv[j])
	{
		//printf("%s [%zu]\n", argv[j], new_line(argv, j));
		if (new_line(argv, j) == 1)
			print_argument(argv, j);
		j++;
	}
	return ;
}

void	builtin_echo(t_command *cmd)
{
	size_t	j;
	size_t	newline;
	char	**argv;
	size_t	i;

	argv = get_array_from_token_lst(cmd->argv);
	/*i = 0;
	while (argv && argv[i])
	{
		printf("elemento %zu: %s\n", i, argv[i]);
		i++;
	}*/
	j = 0;
	newline = 1;
	//printf("kk %zu: %s\n", j, argv[j + 1]);
	if (ft_strncmp1(argv[j + 1], "-n", 2) == 0)
	{
		//printf("holayadios\n");
		newline = new_line(argv, j + 1);
		//ft_putendl_fd(ft_itoa(newline), 1);
		//printf("newline = %zu\n", newline);
		if (newline == 1)
			print_echo_all_args(argv, 0);
		else if (newline == 0)
			print_echo_necesary_args(argv, 2);
	}
	else
		print_echo_all_args(argv, 0);
	if (newline)
		ft_putchar_fd('\n', 1);
	ft_array_free(argv);
	return ;
	
	/*argv = get_array_from_token_lst(cmd->argv);
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
	return ;*/
}
