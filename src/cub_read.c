/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:45:18 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 23:01:58 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	cub_get(int argc, char *argv[], t_cubfile *cubfile)
{
	char	*path_file;
	char	*path_fdf;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3d <filename>\n", 2);
		exit(EXIT_FAILURE);
	}
	path_fdf = ft_strtrim(argv[0], "cub");
	path_file = ft_strjoin(path_fdf, argv[1]);
	cubfile->row_count = 0;
	cubfile->fd = open(path_file, O_RDONLY);
	free(path_file);
	free(path_fdf);
	if (cubfile->fd == -1)
	{
		perror("open() failed");
		exit(EXIT_FAILURE);
	}
}

void	cub_read(t_cubfile *cubfile, int argc, char *argv[])
{
	cub_get(argc, argv, cubfile);
	while (1)
	{
		cubfile->i = get_next_line(cubfile->fd, cubfile->line);
		if (cubfile->i == -1)
			break ;
		if (cubfile->i == 0)
			break ;
		else
		{
			cubfile->points[cubfile->row_count++] = ft_split(*cubfile->line, ' ');
			if (cubfile->row_count == 999999)
			{
				ft_putstr_fd("Error: .cub file exceeds 1m row limit\n", 2);
				ft_split_free(*(cubfile->points), 999999);
				free(*cubfile->line);
				exit(EXIT_SUCCESS);
			}
		}	
		free(*cubfile->line);
	}
	close(cubfile->fd);
}
