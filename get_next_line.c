/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:35:41 by pbuet             #+#    #+#             */
/*   Updated: 2024/11/04 11:12:40 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(sizeof(char) *(len1 + len2 + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = s1[i];
	j = 0;
	while (j < len2)
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static	char	*update_buf(char *buffer)
{
	char	*new;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(buffer)- i + 1));
	if (!new)
		return (NULL);
	j = 0;
	i ++;
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	free(buffer);
	return (new);
}

char	*ft_read(char *buffer, char *tmp, ssize_t bytes_read, int fd)
{
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes_read;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	buffer = ft_read(buffer, tmp, bytes_read, fd);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = update_buf(buffer);
	return (line);
}

// int main() {
//     int fd;
//     char *line;

//     // Ouvrir le fichier en lecture seule
//     fd = open("text.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Erreur lors de l'ouverture du fichier");
//         exit(EXIT_FAILURE);
//     }

//     // Lire chaque ligne du fichier et l'afficher
// 	line = get_next_line(fd);
//         printf("%s", line); // Libérer la mémoire après chaque ligne lue
//     // Fermer le fichier
//     if (close(fd) == -1) {
//         perror("Erreur lors de la fermeture du fichier");
//         exit(EXIT_FAILURE);
//     }

//     return 0;
// }