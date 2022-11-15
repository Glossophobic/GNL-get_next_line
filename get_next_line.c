/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:06:56 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/16 00:15:11 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	char		*buff;
	static char	*saved[OPEN_MAX];

	if (read(fd, NULL, 0) == -1) // to check if the fd is valid
	{
		if (fd != -1)
			free(saved[fd]); // free stuff from previous calls
		saved[fd] = NULL; // why
		return (NULL);
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
	line = ft_substr(saved[fd],
		0, ft_strchr(saved[fd], '\n') - saved[fd] + 1);
	tmp = saved[fd];
	saved[fd] = ft_substr(ft_strchr(saved[fd], '\n') + 1,
		0, ft_strlen(ft_strchr(saved[fd], '\n')));
	free(tmp);
	return (line);
}
// int main()
// {
// 	int fd;

// 	fd = open("sekiro.txt", O_RDONLY);

// 	char *s;
// 	char *s1;
// 	char *s2;
// 	char *s3;
// 	char *s4;
	
// 	s = get_next_line(-1);
// 	printf("%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s\n", s);
// 	free(s);
// }