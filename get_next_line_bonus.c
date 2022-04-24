/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparedes <aparedes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:00:29 by aparedes          #+#    #+#             */
/*   Updated: 2022/04/24 16:58:35 by aparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

static char	*ft_new_text(char *line)
{
	int		index;
	int		k;
	char	*text;

	index = 0;
	while (line[index] !='\n' && line[index])
		index++;
	if (!line[index])
	{
		free(line);
		return(NULL);
	}
	text = malloc(sizeof(char) * (ft_strlen(line) - index + 1));
	if (!text)
		return(NULL);
	index++;
	k = 0;
	while(line[index])
		text[k++]= line[index++];
	text[k] = '\0';
	free(line);
	return (text);	
}

static char	*ft_get_line(char *str)
{
	char	*line;
	int		index;

	index = 0;
	if(str[index] == '\0')
		return (NULL);
	while (str[index] !='\n' && str[index])
		index++;
	line = malloc(sizeof(char) * (index + 2));
	if(!line)
		return(NULL);
	index = 0;
	while (str[index] != '\n' && str[index])
	{
		line[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
	{
		line[index] = str[index];
		index ++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			readed;
	char		*buffer;
	char		*line;
	static char	*text[256];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 255)
		return (NULL);
	readed = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (readed != 0 && !(ft_strchr(text[fd], '\n')))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		text[fd] = ft_strjoin(text[fd], buffer);
	}
	free(buffer);
	line = ft_get_line(text[fd]);
	text[fd] = ft_new_text(text[fd]);
	return (line);
}

/* 
int   main()
{
	int fd;
	char *line;
	int	fd1;

	fd = open("text1", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
			printf("%s", line);
			free(line);
	}
	fd1 = open("text2", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd1);
		if (line == NULL)
			break;
			printf("%s", line);
			free(line);
	}
	// system("leaks a.out");
}
 */