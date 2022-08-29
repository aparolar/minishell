/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:35:36 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 11:35:49 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delim_and(t_list **token_lst, char *str)
{
	delim_generic2(token_lst, str, TOKEN_SAND, TOKEN_DAND);
}
