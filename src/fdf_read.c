/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:45:18 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 14:10:32 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_get(int argc, char *argv[], t_gnl *gnl)
{
	char	*path_file;
	char	*path_fdf;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <filename>\n", 2);
		exit(0);
	}
	path_fdf = ft_strtrim(argv[0], "fdf");
	path_file = ft_strjoin(path_fdf, argv[1]);
	gnl->row_count = 0;
	gnl->fd = open(path_file, O_RDONLY);
	free(path_file);
	free(path_fdf);
	if (gnl->fd == -1)
	{
		perror("open() failed");
		exit(0);
	}
}

void	fdf_read(t_gnl	*gnl, int argc, char *argv[])
{
	fdf_get(argc, argv, gnl);
	while (1)
	{
		gnl->i = get_next_line(gnl->fd, gnl->line);
		if (gnl->i == -1)
			break ;
		if (gnl->i == 0)
			break ;
		else
		{
			gnl->points[gnl->row_count++] = ft_split(*gnl->line, ' ');
			if (gnl->row_count == 999999)
			{
				ft_putstr_fd("Error: .fdf file exceeds 1m row limit\n", 2);
				ft_split_free(*(gnl->points), 999999);
				free(*gnl->line);
				exit(0);
			}
		}	
		free(*gnl->line);
	}
	close(gnl->fd);
}
