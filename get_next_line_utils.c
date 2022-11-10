/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:57:33 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/10/26 01:37:42 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
}

char	*ft_strjoin(char *s1, char const *s2)
{
}

char	*ft_strchr(char *buff, char c)
{
}

char	*get_buff(int fd)
{
	char	*buff;
	ssize_t	rbytes;

	buff = malloc(BUFFER_SIZE + 1);
	rbytes = read(fd, buff, BUFFER_SIZE);
	if (rbytes > 0 && rbytes <= BUFFER_SIZE)
	{
		buff[rbytes] = 0;
		return (buff);
	}
	free(buff);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
}
