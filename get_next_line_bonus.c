/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:21:57 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/15 21:35:06 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[OPEN_MAX];
	char		*buff;
	char		*tmp;

	if (read(fd, NULL, 0) == -1)
	{
		if(fd != -1)
			free(saved[fd]);
		saved[fd] = NULL;
		return NULL;
	}
	while (!ft_strchr(saved[fd], '\n'))
	{
		buff = fill_buff(&fd);
		if (!buff)
		{
			if (fd == -1)
			{
				free(saved[fd]);
				saved[fd] = NULL;
				return (NULL);
			}
			line = saved[fd];
			saved[fd] = NULL;
			return (line);
		}
		saved[fd] = ft_strjoin(saved[fd], buff);
		free(buff);
	}
	line = ft_substr(saved[fd], 0, ft_strchr(saved[fd], '\n') - saved[fd] + 1);
	tmp = saved[fd];
	saved[fd] = ft_substr(ft_strchr(saved[fd], '\n') + 1,
		0, ft_strlen(ft_strchr(saved[fd], '\n')));
	free(tmp);
	return (line);
}