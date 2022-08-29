/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:54:51 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/12 19:57:06 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*get_last_command(t_list *cmd_lst)
{
	cmd_lst = ft_lstlast(cmd_lst);
	return (cmd_lst->content);
}
