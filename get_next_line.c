/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:05 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/12 14:26:33 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*protect_on_error(char *buff, int fd)
{
	if (fd < 0)
		return (NULL);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*saved[OPEN_MAX];
	char		*line;
	char		*tmp;
	
	while (ft_strchr(saved[fd], '\n') == 0)
	{
		buffer = fill_buff(fd);
		if (!buffer)
		{
			line = saved[fd];
			saved[fd] = NULL;
			return (protect_on_error(line, fd));
		}
		saved[fd] = ft_strjoin(saved[fd], buffer);
		free(buffer);
	}
	line = ft_substr(saved[fd], 0, ft_strchr(saved[fd], '\n') - saved[fd] + 1);
	tmp = saved[fd];
	saved[fd] = ft_substr(ft_strchr(saved[fd], '\n') + 1, 0, ft_strlen(ft_strchr(saved[fd], '\n')));
	free(tmp);
	return (line);
}