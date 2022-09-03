/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:03:44 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/03 10:36:11 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_prompt(void)
{
	char	*ret;
	char	*user;

	user = get_env_var("USER");
	if (user)
		ret = ft_strjoin(user, "@minishell> ");
	else
		ret = ft_strdup("guest@minishell> ");
	return (ret);
}

static char	*get_input(void)
{
	char	*cmd;
	char	*prompt;

	prompt = get_prompt();
	cmd = readline(prompt);
	free(prompt);
	if (cmd && *cmd)
		add_history(cmd);
	return (cmd);
}

void	get_cmd(void)
{
	char	*cmd;
	t_list	*cmd_lst;

	while (1)
	{
		gs_info()->error = 0;
		gs_info()->heredoc_fd = -1;
		cmd = get_input();
		if (!cmd)
			break ;
		gs_info()->cmd_str = cmd;
		parse_cmd(cmd);
		cmd_lst = lexer();
		if (cmd_lst && !gs_info()->error)
			execute_cmd(cmd_lst, gs_info()->env);
		free_command_lst(&cmd_lst);
		free(cmd);
		ft_lstclear(&gs_info()->tk, free);
		if (gs_info()->error)
			printf("%s", gs_info()->error);
	}
}
