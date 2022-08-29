/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_to_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:14:20 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/04 12:19:47 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*add_path_to_cmd(char *path, char *cmd)
{
	char	*tmp;

	tmp = NULL;
	if (path && cmd)
	{
		tmp = ft_strjoin(path, "/");
		path = tmp;
		tmp = ft_strjoin(tmp, cmd);
		free(path);
	}
	return (tmp);
}
