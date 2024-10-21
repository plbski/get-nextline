/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:28:20 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/21 14:56:08 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#ifndef n 
# define n 1024
#endif
# define BUFFER_SIZE n

typedef struct s_list
{
	void	*s;
	struct s_list *next;
}

char	*get_next_line(int fd)
#endif
