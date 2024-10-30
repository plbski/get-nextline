/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:35:41 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/30 17:11:31 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		len_s3;
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1)
		len_s3 = ft_strlen(s2);
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
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j ++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char	*full_line(char *s, int pos)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * pos);
	if (line == NULL)
		return (NULL);
	while (i < pos)
	{
		line[i] = s[i];
		i ++;
	}
	line[i] = '\0';
	return (line);
}
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			byte_read;
	int			pos;
	int			i;
	char		*line;
	char		*tmp;

	i = 0;
	if (fd < 0 || fd > 255 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		buffer[byte_read] = '\0';
		tmp = ft_strjoin(line, buffer);
		if (!tmp)
		{
			free (line);
			return (NULL);
		}
		free(line);
		line = tmp;
		if ((pos = end_line(line)) != 0)
		{
			tmp = full_line(line, pos);
			if (!tmp)
			{
				free (line);
				return (NULL);
			}
			free(line);
			line = tmp;
			while (pos < BUFFER_SIZE)
			{
				buffer[i] = buffer[pos];
				pos ++;
				i ++;
			}
			return (line);
		}
		if (byte_read == 0)
			return(line);
	}
}

// int main()
// {
// 	int fd;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return(0);
// }