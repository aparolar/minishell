/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:11:46 by icastell          #+#    #+#             */
/*   Updated: 2022/09/01 17:08:36 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	update_var_env(t_builtin *builtin)
{
	if (builtin->pwd)
		set_env_var("PWD", builtin->pwd);
	if (builtin->oldpwd)
	{
		if (!get_env_var("OLDPWD"))
			add_env_var(ft_strdup("OLDPWD"), builtin->oldpwd);
		else
			set_env_var("OLDPWD", builtin->oldpwd);
	}
	return ;
}

static void	change_to_dir(char *str, t_builtin *builtin)
{
	if (chdir(str) == -1)
	{
		show_error(builtin->cmd, str);
		free(builtin->pwd);
	}
	else
	{
		builtin->oldpwd = builtin->pwd;
		builtin->pwd = getcwd(NULL, 0);
		update_var_env(builtin);
	}
	return ;
}

static void	change_to_home(t_builtin *builtin)
{
	if (chdir(builtin->home) == -1)
	{
		show_error(builtin->cmd, builtin->home);
		chdir("/");
	}
	builtin->oldpwd = builtin->pwd;
	builtin->pwd = getcwd(NULL, 0);
	update_var_env(builtin);
	return ;
}

void	builtin_post_cd(t_command *cmd)
{
	char		**argv;
	char		*pwd;
	char		*home;
	t_builtin	builtin;

	builtin.oldpwd = NULL;
	builtin.cmd = cmd;
	argv = get_array_from_token_lst(cmd->argv);
	if ((argv) && (ft_array_count(argv)) > 0)
	{
		pwd = get_env_var("PWD");
		builtin.pwd = ft_strdup(pwd);
		home = get_env_var("HOME");
		if (home == NULL)
			builtin.home = "";
		else
			builtin.home = home;
		if (argv[1])
			change_to_dir(argv[1], &builtin);
		else if (!argv[1])
			change_to_home(&builtin);
		free(argv);
	}
	return ;
}

void	builtin_cd(t_command *cmd)
{
	(void)cmd;
	return ;
}
