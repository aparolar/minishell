/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:53:26 by aparolar          #+#    #+#             */
/*   Updated: 2022/05/15 10:22:49 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	This function take a path to file or directory and returns :
	0 it's a directory
	1 it's a file
*/

int	is_directory(char *dir)
{
	DIR	*ret;

	ret = opendir(dir);
	if (ret)
	{
		//free(ret);
		return (1);
	}
	return (0);
}
