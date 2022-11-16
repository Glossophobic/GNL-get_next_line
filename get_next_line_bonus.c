/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:59:39 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/16 20:10:49 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fnc(int fd, char **saved, char *line, char *tmp, char *buff)
{
	while (!ft_strchr(*saved, '\n'))
	{
		buff = fill_buff(&fd);
		if (!buff)
		{
			if (fd == -1)
			{
				free(saved);
				*saved = NULL;
				return (NULL);
			}
			line = *saved;
			*saved = NULL;
			return (line);
		}
		*saved = ft_strjoin(*saved, buff);
		free(buff);
	}
	line = ft_substr(*saved, 0, ft_strchr(*saved, '\n') - *saved + 1);
	tmp = *saved;
	*saved = ft_substr(ft_strchr(*saved, '\n') + 1, 0, ft_strlen(ft_strchr(*saved, '\n')));
	free(tmp);
	return (line);
}

#include <string.h>
char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	char		*buff;
	static char	*saved[OPEN_MAX];
	
	buff = NULL;
	tmp = NULL;
	line = NULL;

	if (read(fd, NULL, 0) == -1) // to check if the fd is valid
	{
		if (fd != -1)
			free(saved[fd]); // free stuff from previous callsc
		saved[fd] = NULL;
		return (NULL);
	}
	return (fnc(fd, &saved[fd], line, tmp, buff));
}
