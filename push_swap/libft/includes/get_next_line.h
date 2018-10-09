/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:23:31 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/12 16:23:34 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 32

typedef struct				s_data
{
	int						r;
	char					b[BUFF_SIZE + 1];
	int						b_index;
	int						fd;
	struct s_data			*next;
	struct s_data			*prev;
}							t_data;

int							get_next_line(const int fd, char **line);

#endif
