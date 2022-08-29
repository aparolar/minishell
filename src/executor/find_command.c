/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:34:56 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/04 15:16:49 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_local_command(char *cmd)
{
	if (cmd)
	{
		if (ft_strchr(cmd, '/'))
			return (1);
	}
	return (0);
}

char	*find_command(char *cmd)
{
	char	**paths;
	char	**tmp;
	char	*tcmd;

	if (is_local_command(cmd))
		return (ft_strdup(cmd));
	tcmd = NULL;
	paths = ft_split(get_env_var("PATH"), ':');
	tmp = paths;
	if (paths)
	{
		while (*tmp)
		{
			tcmd = add_path_to_cmd(*tmp, cmd);
			if (access(tcmd, F_OK) == 0)
				break ;
			free(tcmd);
			tcmd = NULL;
			tmp++;
		}
	}
	ft_array_free(paths);
	return (tcmd);
}
