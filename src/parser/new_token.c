/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:33:06 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/12 11:35:44 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*new_token(int flags)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token)
	{
		token->flags = flags;
		token->start = 0;
	}
	return (token);
}
