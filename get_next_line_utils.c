/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:49:57 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/15 01:34:35 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*psrc;
	char	*pdest;

	psrc = (char *)src;
	pdest = (char *)dst;
	if (!src && !dst)
		return (NULL);
	while (n > 0)
	{
		*pdest++ = *psrc++;
		n--;
	}
	return (dst);
}

char	*ft_strchr(char *buff, char c)
{
	if (buff != NULL)
	{
		while (*buff && *buff != c)
			buff++;
		if (*buff == c)
			return (buff);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	s1len = ft_strlen(s1);
	s2len = ft_strlen((char *)s2);
	str = malloc((s1len + s2len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len);
	str[s1len + s2len] = '\0';
	free(s1);
	return (str);
}

char	*fill_buff(int fd, char *saved)
{
	char	*buff;
	ssize_t	rd_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	rd_bytes = read(fd, buff, BUFFER_SIZE);
	if (rd_bytes > 0)
	{
		buff[rd_bytes] = '\0';
		return (buff);
	}
	else if (rd_bytes == -1)
		free(saved);
	free(buff);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	rem;

	rem = ft_strlen(s + start);
	if (len > rem)
		len = rem;
	if (len <= 0 || !s)
		return (NULL);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = 0;
	return (sub);
}
