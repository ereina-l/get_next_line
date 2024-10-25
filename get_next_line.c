/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:30:03 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/25 16:46:26 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_extract(int fd)
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
	char *tmp = ft_get_extract(fd);
	return (tmp);
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