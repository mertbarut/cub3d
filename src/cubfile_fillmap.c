/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_fillmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:04:14 by dmylonas          #+#    #+#             */
/*   Updated: 2022/01/03 15:43:59 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_valid_char(t_cubfile *f, char c, int *player)
{
	if (ft_strchr("01 NSEW", c))
	{
		if (ft_isalpha(c))
		{
			if (*player)
				return (0);
			f->flag_player_direction = c;
			*player = 1;
		}
		return (1);
	}
	return (0);
}

static void	fill_row_extra(t_data *cub, int *player, int index, int col)
{
	t_cubfile		*f;

	f = cub->file;
	if (!(is_valid_char(f, f->line[col], player)))
	{
		cubfile_error(cub, 4);
	}
	if (ft_isalpha(f->line[col]))
	{
		cub->player->pos.x = (double)index + 0.5;
		cub->player->pos.y = (double)col + 0.5;
		f->line[col] = '0';
	}
	while (f->line[col] == ' ')
	{
		f->map[index][col] = 2;
		col++;
	}
	f->map[index][col] = f->line[col] - 48;
}

static void	fill_row(t_data *cub, int index, int *player)
{
	int			col;
	t_cubfile	*f;

	f = cub->file;
	col = f->max_rows;
	f->map[index] = (int *)malloc((col + 1) * sizeof(int));
	col = 0;
	while (f->line[col] != '\0')
	{
		fill_row_extra(cub, player, index, col);
		col++;
	}
	while (col < f->max_rows)
	{
		f->map[index][col] = 3;
		col++;
	}
}

void	cubfile_fillmap(t_data *cub, int fd)
{
	int				player;
	int				row;
	t_cubfile		*f;
	int				start_map;

	f = cub->file;
	row = 0;
	player = 0;
	start_map = 0;
	while (get_next_line(fd, &f->line, start_map))
	{
		if (*f->line == '5')
			cubfile_error(cub, 9);
		if (((*f->line == '1') || (*f->line == ' ')))
		{
			start_map = 1;
			fill_row(cub, row, &player);
			row++;
		}
		free_double((void **)&f->line);
	}
}
