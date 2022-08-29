/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:59:59 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/15 11:00:07 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delim_or(t_list **token_lst, char *str)
{
	delim_generic2(token_lst, str, TOKEN_SOR, TOKEN_DOR);
}
