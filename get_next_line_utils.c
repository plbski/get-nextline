/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:57:49 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/30 17:21:02 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int end_line(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
}

void	ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[c])
	{
		s[i] = s[c];
		i ++;
		c ++;
	}
}

char	*ft_strdup(const char *s1, int pos)
{
	char	*s2;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	s2 = malloc(sizeof(char ) * pos + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i <= pos)
	{
		s2[i] = s1[i];
		i ++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s)
		i++;
	return (i);
}
