/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:30:03 by ereina-l          #+#    #+#             */
/*   Updated: 2024/11/22 15:10:36 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// len + 2 when allocating memory since we take into account \n and \0
static char	*ft_create_stash(int fd, char *stash)
{
	int		read_bytes;
	char	*buffer;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free(stash), NULL);
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
		if (ft_find_newline(stash, 10) || read_bytes == 0)
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	line = ft_calloc((len + 2), sizeof(char));
	i = 0;
	while (i <= len)
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

static char	*ft_update_stash(char *stash)
{
	char	*updated_stash;
	size_t	start;
	size_t	i;

	if (!stash)
		return (NULL);
	start = 0;
	while (stash[start] && stash[start] != '\n')
		start++;
	if (!stash[start])
	{
		free(stash);
		return (NULL);
	}
	updated_stash = ft_calloc((ft_strlen(stash) - start + 1), sizeof(char));
	i = 0;
	start++;
	while (stash[start])
		updated_stash[i++] = stash[start++];
	free(stash);
	return (updated_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_create_stash(fd, stash);
	line = ft_extract_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
} */
