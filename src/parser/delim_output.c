/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:59:05 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 10:59:16 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delim_output(t_list **token_lst, char *str)
{
	delim_generic2(token_lst, str, TOKEN_SOUTPUT, TOKEN_DOUTPUT);
}
