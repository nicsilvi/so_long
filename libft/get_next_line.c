/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:33:52 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 09:03:42 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extra_readmore(char *buffer, int readed, char *located)
{
	char	*temp;

	buffer[readed] = '\0';
	temp = ft_strjoin(located, buffer);
	return (temp);
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
			located = extra_readmore(buffer, readed, located);
		else if (readed == 0)
		{
			if (located && located[0] != '\0')
				return (ft_free(&buffer), located);
			return (ft_free(&buffer), ft_free(&located));
		}
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

	if (!ft_strchr(located, '\n'))
		full_line = ft_substr(located, 0, ft_strlen(located));
	else
	{
		ptr = ft_strchr(located, '\n');
		len = (ptr - located) + 1;
		full_line = ft_substr(located, 0, len);
	}
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
		new_locate = ft_substr(located, len, ft_strlen(located) - len);
		ft_free(&located);
	}
	return (new_locate);
}

char	*get_next_line(int fd)
{
	static char	*located;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!located || (located && !ft_strchr(located, '\n')))
		located = readmore(located, fd);
	if (!located)
		return (NULL);
	line = ft_full_line(located);
	if (!line)
		return (ft_free(&located));
	located = clean_locate(located);
	return (line);
}
