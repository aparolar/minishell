/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:30:50 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 20:21:39 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	if (!pwd)
		pwd = ft_strdup("");
	return (pwd);
}

static char	*get_minishell_name(char *str)
{
	if (ft_strchr(str, '/'))
		str++;
	while (ft_strchr(str, '/'))
		str++;
	return (str);
}

static void	initialize(void)
{
	char	*shlvl;
	char	*pwd;

	shlvl = get_env_var("SHLVL");
	pwd = get_env_var("PWD");
	if (shlvl)
		set_env_var("SHLVL", ft_itoa(ft_atoi(shlvl) + 1));
	else
		add_env_var(ft_strdup("SHLVL"), ft_strdup("1"));
	if (!pwd)
		add_env_var(ft_strdup("PWD"), get_pwd());
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	if (gs_info())
	{
		gs_info()->minishell_name = get_minishell_name(argv[0]);
		init_main_signals();
		init_delims();
		parse_env(env);
		initialize();
		get_cmd();
		clean_all();
	}
	return (0);
}
