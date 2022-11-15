/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:06:56 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/15 01:35:08 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*error_check(char *line, int fd)
{
	if (fd < 0)
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[OPEN_MAX];
	char		*buff;
	char		*tmp;

	while (!ft_strchr(saved[fd], '\n'))
	{
		buff = fill_buff(fd, saved[fd]);
		if (!buff)
		{
			line = saved[fd];
			saved[fd] = NULL;
			return (error_check(line, fd));
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
// int main()
// {
// 	int fd;

// 	fd = open("sekiro.txt", O_RDONLY);

// 	char *s;
// 	char *s1;
// 	char *s2;
// 	s = get_next_line(fd);
// 	printf("%s\n", s);
// 	free(s);	
	
// 	s = get_next_line(fd);
// 	printf("%s\n", s);
// 	s1 = get_next_line(fd);
// 	printf("%s\n", s1);
// 	s2 = get_next_line(fd);
// 	printf("%s\n", s2);

// 	system("leaks a.out");
		
// }