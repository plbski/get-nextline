/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:42:15 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/21 14:57:26 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int	i = 0;
	int start;
	int check;
	char *s = NULL;
	s_list lst;
	
	start = i;
		s = malloc(BUFFER_SIZE + 1);
		if (s == NULL)
			return(NULL);
	while ((check = read(fd, s, 1)) > 0 && s[i] != '\n')
	{
		i ++;
		if (i >= BUFFER_SIZE)
			break;;
	}
	if (check == 0)
	{
		free (s);
		return (NULL);
	}
	s[i + 1] = '\0';
	return(&s[j]);
}
