/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_flag_isempty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:02:42 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 11:02:51 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_token_flag_isempty(t_token *token, int flags)
{
	set_token_flag_if(token, flags, TOKEN_EMPTY);
}
