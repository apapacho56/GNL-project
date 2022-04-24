/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparedes <aparedes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:00:29 by aparedes          #+#    #+#             */
/*   Updated: 2022/04/24 16:55:43 by aparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_strdup(char *src)
{
	size_t	len;
	int		i;
	char	*dest;

	len = ft_strlen(src);
	dest = malloc(len + 1);
	i = 0;
	if (dest == 0)
		return (0);
	else
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int	c2;
	int	c1;

	if(!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (0);
	c2 = 0;
	c1 = 0;
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!buffer)
		return (NULL);
	while (s1[c1] != '\0')
	{
		buffer[c1] = s1[c1];
		c1++;
	}
	c1 = ft_strlen(s1);
	while (s2[c2] != '\0')
	{
		buffer[c1] = s2[c2];
		c1++;
		c2++;
	}
	buffer[c1] = '\0';
	free(s1);
	return (buffer);
}

char	*ft_strchr(char *s, int c)
{
	int		counter;

	counter = 0;
	if (!s)
		return ((char *)&s[counter]);
	while (counter < (int)ft_strlen(s) + 1)
	{
		if (*(s + counter) == (char)c)
			return ((char *)s + counter);
		counter ++;
	}
	return (NULL);
}


size_t	ft_strlen (char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count ++;
	return (count);
}
