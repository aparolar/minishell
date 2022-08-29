/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:58:42 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 10:58:44 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delim_input(t_list **token_lst, char *str)
{
	delim_generic2(token_lst, str, TOKEN_SINPUT, TOKEN_DINPUT);
}
