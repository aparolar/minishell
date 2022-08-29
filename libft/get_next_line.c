/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2022/04/25 17:15:31 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(char **buffer, char **line, int bytes)
{
	char	*s;

	s = *buffer;
	if (!s)
		*line = ft_calloc(1, sizeof(char));
	else if (!ft_strchr(s, '\n'))
	{
		*line = ft_substr(s, 0, ft_strlen(s));
		free(s);
		*buffer = 0;
	}
	else
	{
		*line = ft_substr(s, 0, ft_strchr(s, '\n') - s);
		*buffer = ft_strrem(s, 0, ft_strchr(s, '\n') - s + 1);
		free(s);
		s = 0;
		bytes = 1;
	}
	return (bytes);
}

int	get_next_line(int fd, char **line)
{
	static char	*list[4096];
	char		buff[GNL_BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	ret = read(fd, buff, GNL_BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		if (!list[fd])
			list[fd] = ft_calloc(1, sizeof(char));
		tmp = list[fd];
		list[fd] = ft_strcat(tmp, buff);
		free(tmp);
		if (ft_strchr(list[fd], '\n'))
			break ;
		ret = read(fd, buff, GNL_BUFFER_SIZE);
	}
	if (ret == -1)
		return (-1);
	return (get_line(&list[fd], line, ret));
}
