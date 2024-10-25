/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:30:03 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/25 16:22:05 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	void	*tmp;
	int		rvalue;

	tmp = (void *)malloc(BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (NULL);
	rvalue = read(fd, tmp, BUFFER_SIZE);
	if (rvalue <= 0)
		return (NULL);
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