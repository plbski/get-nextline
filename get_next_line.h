/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:58:13 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/30 17:06:00 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 22
#endif

int		ft_strlen(const char *s);
int		end_line(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2, int pos);
void	ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1, int pos);

#endif
