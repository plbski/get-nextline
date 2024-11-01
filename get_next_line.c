/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:35:41 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/30 17:42:16 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, char const *s2, int pos)
{
	int		len_s3;
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1)
		len_s3 = pos;
	else
		len_s3 = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * len_s3 + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i ++;
	}
	while (s2[j] && j <= pos)
	{
		s3[i + j] = s2[j];
		j ++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	int			pos;
	char		*line;
	char		*tmp;
	
	line = NULL;
	pos = 0;
	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > 255))
		return (NULL);
	 while (1) {
		if (buffer[0] == '\0')
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				return line;
			buffer[bytes_read] = '\0';
		}
        pos = end_line(buffer);
		if (pos >= 0)
		{ 
			tmp = ft_strjoin(line, buffer, pos);
			if (!tmp)
			{
				free(line);
				return NULL;
        	}
			free(line);
			for (int i = 0; buffer[pos]; i++, pos++) {
				buffer[i] = buffer[pos + 1];
			}
			buffer[pos] = '\0';
			return tmp;
        }
        tmp = ft_strjoin(line, buffer, bytes_read - 1);
        if (!tmp) 
		{
            free(line);
            return NULL;
        }
        free(line);
        line = tmp;
		buffer[0] = '\0';
    }
}

// int main()
// {
// 	int fd;
// 	char *line;
// 	fd = open("text.txt", O_RDONLY);
	
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return(0);
// }