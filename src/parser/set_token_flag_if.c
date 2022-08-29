/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_flag_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:03:04 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 11:03:06 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_token_flag_if(t_token *token, int flags, int flag_cond)
{
	if (token->flags & flag_cond)
	{
		token->flags ^= flags;
		token->flags |= flags;
	}
}
