/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_delims.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:10:41 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/16 14:20:00 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_delims(void)
{
	t_list	*delim_lst;

	delim_lst = 0;
	ft_lstadd_back(&delim_lst, new_delim_node(' ', delim_space));
	ft_lstadd_back(&delim_lst, new_delim_node('<', delim_input));
	ft_lstadd_back(&delim_lst, new_delim_node('>', delim_output));
	ft_lstadd_back(&delim_lst, new_delim_node('|', delim_or));
	ft_lstadd_back(&delim_lst, new_delim_node('&', delim_and));
	ft_lstadd_back(&delim_lst, new_delim_node(';', delim_end));
	gs_info()->delim = delim_lst;
}
