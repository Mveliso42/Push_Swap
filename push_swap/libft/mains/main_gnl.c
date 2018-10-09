/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:55:12 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/22 18:55:17 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int        main(int argc, char **argv)
{
	int        fd;
	int        status;
	char    *line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while ((status = get_next_line(fd, &line)) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	ft_putnbr(status);
	if (argc == 2)
		close(fd);
}
