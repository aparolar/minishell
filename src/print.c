/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:21:33 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/20 22:57:50 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(void *content)
{
	t_token	*tkn;

	tkn = content;
	printf("----------------------\n");
	printf("TOKEN [%d] [%s]\n", tkn->flags, tkn->start);
	printf("----------------------\n");
}
