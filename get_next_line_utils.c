/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereina-l <ereina-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:31:50 by ereina-l          #+#    #+#             */
/*   Updated: 2024/10/29 12:20:38 by ereina-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_newline(char *s)
{
	while (*s != '\0')
	{
		if (*s == 10)
			return (s);
		s++;
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
char	*ft_strdup(char *s)
{
	size_t		len;
	char		*dup;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}
size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((size_t)ft_strlen((char *)src));
}
char	*ft_strjoin(char *dest, char *src)
{
	int		i;
	int		j;
	char	*join;

	if (!dest)
		return (ft_strdup(src));
	join = malloc((ft_strlen(dest) + ft_strlen(src) + 1) * sizeof (char));
	if (!join)
		return (NULL);
	i = 0;
	while (dest[i])
	{
		join[i] = dest[i];
		i++; 
	}
	free (dest);
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

