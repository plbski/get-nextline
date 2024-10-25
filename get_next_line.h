/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:58:13 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/24 15:45:01 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include<unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(const char *s);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*fulline(int fd);
void	ft_lstclear(t_list **lst);
#endif
