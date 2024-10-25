/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:35:41 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/24 15:51:19 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s3;
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	len_s3 = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * len_s3 + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
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

char	*fulline(int fd)
{
	int		i = 0;
	int		check;
	char	*s;
	char	buf[BUFFER_SIZE + 1];
	
	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (s == NULL)
		return(NULL);
	while ((check = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i ++;
		if (i >= BUFFER_SIZE )
		{
			s = ft_strjoin(s, buf);
			i = 0;
		}
	}
	if (check == 0)
	{
		free (s);
		return (NULL);
	}
	buf[i] = '\0';
	s = ft_strjoin(s, buf);
	return (s);
}
char	*get_next_line(int fd)
{
	static	t_list *lst;
	char	*line;
	
	if (fd > 256 || fd < 0)
		return (NULL);
	line = fulline(fd);
	if (line)
	{
		t_list *new = ft_lstnew(line);
		ft_lstadd_back(&lst, new);
	}
	else 
		ft_lstclear(&lst);
	return(ft_lstlast(lst)->content);
}
