/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:49:25 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 11:49:35 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_env_var(char *key, char *value)
{
	t_key_value_var	*node;

	if (!get_env_var(key))
	{
		node = malloc(sizeof(t_key_value_var));
		node->key = key;
		node->value = value;
		add_env_entry(node);
		free(node);
	}
}
