/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:31:50 by ereina-l          #+#    #+#             */
/*   Updated: 2024/11/08 16:50:30 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_newline(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *dest, char *src)
{
	int		i;
	int		j;
	char	*join;

	join = malloc((ft_strlen(dest) + ft_strlen(src) + 1) * sizeof (char));
	if (!join)
		return (NULL);
	i = 0;
	while (dest[i])
	{
		join[i] = dest[i];
		i++;
	}
	free(dest);
	j = 0;
	while (src[j])
	{
		join[i] = src[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}