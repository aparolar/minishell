/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:23:15 by aparolar          #+#    #+#             */
/*   Updated: 2022/07/02 13:10:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_main_signals(void)
{
	signal(SIGINT, on_father_signal);
	signal(SIGQUIT, on_father_signal);
	signal(SIGTSTP, SIG_IGN);
}
