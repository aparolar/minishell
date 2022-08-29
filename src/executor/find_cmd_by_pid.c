/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_by_pid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:20:01 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/12 18:24:42 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*find_cmd_by_pid(t_command *head, int pid)
{
	while (head)
	{
		if (head->pid == pid)
			return (head);
		head = get_next_command(head);
	}
	return (NULL);
}
