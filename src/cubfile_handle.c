/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:04:17 by dmylonas          #+#    #+#             */
/*   Updated: 2022/01/03 15:38:06 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	print_2d_map(t_cubfile *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->n_rows)
	{
		j = 0;
		while (j < file->max_rows)
		{
			if (file->map[i][j] == 0)
				printf(" ");
			else
				printf("%d", file->map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	free_double(void **to_free)
{
	if (*to_free)
		free(*to_free);
	*to_free = NULL;
}

static void	file_parse_init(t_data *cub, t_cubfile *file)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		file->path[i] = NULL;
		file->rgb_color_floor[i] = -1;
		file->rgb_color_ceiling[i] = -1;
		i++;
	}
	file->path[3] = NULL;
	cub->color_floor = -1;
	cub->color_ceiling = -1;
	file->flag_player_direction = '\0';
	cub->player->pos.x = 0;
	cub->player->pos.y = 0;
	file->max_rows = 0;
	file->n_rows = 0;
}

void	cubfile_handle(t_data *cub, const char *path)
{
	int			fd;
	t_cubfile	*f;

	f = cub->file;
	file_parse_init(cub, f);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		cubfile_error(cub, 0);
	while (get_next_line(fd, &f->line, 0))
	{
		cubfile_configure(f, cub);
		free_double((void **)&f->line);
	}
	free_double((void **)&f->line);
	close(fd);
	cubfile_setcolor(cub);
	fd = open(path, O_RDONLY);
	f->map = (int **)malloc((f->n_rows + 1) * sizeof(int *));
	cubfile_fillmap(cub, fd);
	close(fd);
	print_2d_map(f);
	cubfile_checkmap(cub);
}
