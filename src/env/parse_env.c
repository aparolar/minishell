/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:54:51 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/13 11:56:03 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_env(char **env)
{
	t_key_value_var	*env_value;

	while (*env)
	{
		env_value = get_env_key_value(*env);
		add_env_entry(env_value);
		free(env_value);
		env++;
	}
}
