/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:05 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/10 15:35:21 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	char		*buffer;
	static char	*str[OPEN_MAX];

	while (ft_strchr(str[fd], '\n') == 0)
	{
		buffer = get_buffer(fd);
		if (!buffer)
		{
			line = str[fd];
			str[fd] = NULL;
			return (protection(line, fd));
		}
		str[fd] = ft_strjoin(str[fd], buffer);
		free(buffer);
	}
	line = ft_substr(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd] + 1);
	tmp = str[fd];
	str[fd] = ft_substr(ft_strchr(str[fd], '\n') + 1, 0, ft_strlen(ft_strchr(str[fd], '\n') + 1));
	free(tmp);
	return (line);
}
#include <fcntl.h>
int main()
{
	int fd = open("new.c", O_CREAT | O_RDWR);
	write(fd, "Hello\nWorld\nskdjfhsdkfjhsdfksdfs\ndskfjhsdkfjhdskfjhsdkfjsdhfhdksjfhdhdsf\n", 137);
	get_next_line(fd);
}