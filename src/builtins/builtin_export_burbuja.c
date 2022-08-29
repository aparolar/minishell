/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_burbuja.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:20:33 by icastell          #+#    #+#             */
/*   Updated: 2022/06/28 18:03:22 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	make_swap(t_export *export)
{
	int		j;
	char	*aux;

	j = export->index;
	export->name_1 = ft_substr(export->str[j], 0,
			get_index(export->str[j], '='));
	export->name_2 = ft_substr(export->str[j + 1], 0,
			get_index(export->str[j + 1], '='));
	if (ft_strncmp(export->name_1, export->name_2,
			ft_strmaxlen(export->name_1, export->name_2)) > 0)
	{
		aux = export->str[j];
		export->str[j] = export->str[j + 1];
		export->str[j + 1] = aux;
	}
	free(export->name_1);
	free(export->name_2);
	return ;
}

static void	burbuja(t_export *export)
{
	int		i;
	int		j;

	i = 0;
	while ((export->str[i] != (void *)0) && (i <= (export->length - 2)))
	{
		j = 0;
		while (j <= (export->length - 2 - i))
		{
			export->index = j;
			make_swap(export);
			j++;
		}
		i++;
	}
	return ;
}

static void	insert_quotes(t_export *export, char *str)
{
	char	*aux1;
	char	*aux2;
	int		length;
	int		index;

	length = ft_strlen(str);
	index = get_index(str, '=');
	if (str[index + 1] == '\1')
		export->aux = ft_substr(str, 0, index);
	else if (str[index + 1] != '\1')
	{
		aux1 = ft_substr(str, 0, index + 1);
		aux1 = ft_strjoin_v2(aux1, "\"");
		aux2 = ft_substr(str, index + 1, length - (index + 1));
		aux2 = ft_strjoin_v2(aux2, "\"");
		aux1 = ft_strjoin_v2(aux1, aux2);
		export->aux = ft_strdup(aux1);
		free(aux1);
		free(aux2);
	}
	return ;
}

void	print_export(t_export *export)
{
	int	i;

	i = 0;
	while (export->str[i] != (void *)0)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		insert_quotes(export, export->str[i]);
		ft_putstr_fd(export->aux, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		free(export->str[i]);
		free(export->aux);
		i++;
	}
	free(export->str);
	return ;
}

void	builtin_export_burbuja(void)
{
	t_export	export;

	export.length = get_env_size();
	export.str = get_env_array();
	burbuja(&export);
	print_export(&export);
	return ;
}
