/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:33:52 by smercado          #+#    #+#             */
/*   Updated: 2024/07/19 08:26:12 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*readmore(char *located, int fd)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&located));
	buffer[0] = '\0';
	while (readed > 0 && !ft_strchr(buffer, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed > 0)
		{
			buffer[readed] = '\0';
			located = ft_strjoin(located, buffer);
		}
		else if (readed == 0)
			return (ft_free(&buffer), ft_free(&located));
	}
	ft_free(&buffer);
	if (readed == -1)
		return (ft_free(&located));
	return (located);
}

char	*ft_full_line(char *located)
{
	char	*ptr;
	size_t	len;
	char	*full_line;

	ptr = ft_strchr(located, '\n');
	len = (ptr - located) + 1;
	full_line = ft_substr(located, 0, len);
	if (!full_line)
		return (NULL);
	return (full_line);
}

char	*clean_locate(char *located)
{
	char	*ptr;
	char	*new_locate;
	size_t	len;

	ptr = ft_strchr(located, '\n');
	if (!ptr)
	{
		new_locate = NULL;
		return (ft_free(&located));
	}
	else
	{
		len = (ptr - located) + 1;
		new_locate = ft_substr(located, len, ft_strlen(located));
		ft_free(&located);
	}
	return (new_locate);
}

char	*get_next_line(int fd)
{
	static char	*located[1024];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!located[fd] || (located[fd] && !ft_strchr(located[fd], '\n')))
		located[fd] = readmore(located[fd], fd);
	if (!located[fd])
		return (NULL);
	line = ft_full_line(located[fd]);
	if (!line)
		return (ft_free(&located[fd]));
	located[fd] = clean_locate(located[fd]);
	return (line);
}
