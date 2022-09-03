/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_main_signals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:14:27 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/03 18:27:31 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	disable_main_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
