/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:53:49 by aparolar          #+#    #+#             */
/*   Updated: 2022/01/03 17:11:20 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*gs_info(void)
{
	static t_minishell	*t;

	if (!t)
		t = ft_calloc(1, sizeof(t_minishell));
	return (t);
}
