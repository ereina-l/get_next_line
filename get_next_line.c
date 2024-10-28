/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:30:03 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/28 13:28:07 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// esto ya hace otra cosa , cambiar char	*ft_get_extract(int fd)
{
	void	*tmp;
	int		rvalue;

	while (1)
	{
		tmp = (void *)malloc(BUFFER_SIZE * sizeof(char));
		if (!tmp)
			return (NULL);
		rvalue = read(fd, tmp, BUFFER_SIZE);
		if (rvalue <= 0)
			return (NULL);
		if (ft_find_newline((char *)tmp))
			return (tmp);
	}
}
char	*get_next_line(int fd)
{
	static char	*stash;
	char	*buffer;
	char	*line;
	int		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || 
	!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (NULL);
	while (1)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(stash))
			break ;
	}
	free (buffer);
	line = ft_get_extract(stash);
	stash = update_stash(stash);
	return (line);
}

int	main(void)
{
	int	fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
 	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);

	return (0);

}