/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:06:16 by aparolar          #+#    #+#             */
/*   Updated: 2022/06/02 11:40:02 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_str_count_substr(char *str, char *sstr)
{
	int		ret;
	char	*tmp;

	if (!str || !sstr)
		return (0);
	ret = 0;
	tmp = ft_strnstr(str, sstr, ft_strlen(str));
	while (tmp && *tmp)
	{
		tmp = ft_strnstr(tmp, sstr, ft_strlen(tmp));
		if (tmp && *tmp)
		{
			tmp += ft_strlen(sstr);
			ret++;
		}
	}
	return (ret);
}

static char	*ft_allocstr(char *str, char *ss, char *sr)
{
	char	*ret;
	int		slen;

	slen = ft_str_count_substr(str, ss);
	if (!slen)
		return (0);
	slen *= ft_strlen(sr) - ft_strlen(ss);
	ret = malloc(ft_strlen(str) + slen + 1);
	if (!ret)
		return (0);
	ret[ft_strlen(str) + slen] = 0;
	return (ret);
}

char	*ft_strreplace(char *str, char *search, char *replace)
{
	char	*ret;
	char	*tret;
	char	*next;

	if (!str || !*str || !search || !*search || !replace)
		return (0);
	ret = ft_allocstr(str, search, replace);
	tret = ret;
	next = str;
	while (ret && next && *next)
	{
		next = ft_strnstr(next, search, ft_strlen(next));
		if (next)
		{
			ft_memcpy(tret, str, next - str);
			tret = tret + (next - str);
			ft_memcpy(tret, replace, ft_strlen(replace));
			tret = tret + ft_strlen(replace);
			str = next + ft_strlen(search);
			next = str;
		}
		else if (ft_strlen(str) > 0)
			ft_memcpy(tret, str, ft_strlen(str));
	}
	return (ret);
}
