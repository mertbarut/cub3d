/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:09:37 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/28 15:38:46 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_helper(t_data *fdf, t_line *line, int color)
{
	while (1)
	{
		pixel_put(fdf, line->x0, line->y0, color);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		line->e2 = line->err;
		if (line->e2 > -(line->dx))
		{
			line->err -= line->dy;
			line->x0 += line->sx;
		}
		if (line->e2 < line->dy)
		{
			line->err += line->dx;
			line->y0 += line->sy;
		}
	}
}

static void	draw_line(t_data *fdf, t_pixel *p0, t_pixel *p1, t_map *map)
{
	t_line	line;

	line.x0 = (p0->x - map->ofs_y) * fdf->map.unit;
	line.y0 = (p0->y - map->ofs_x) * fdf->map.unit;
	line.x1 = (p1->x - map->ofs_y) * fdf->map.unit;
	line.y1 = (p1->y - map->ofs_x) * fdf->map.unit;
	line.dx = abs(line.x1 - line.x0);
	if (line.x0 < line.x1)
		line.sx = 1;
	else
		line.sx = -1;
	line.dy = abs(line.y1 - line.y0);
	if (line.y0 < line.y1)
		line.sy = 1;
	else
		line.sy = -1;
	if (line.dx > line.dy)
		line.err = line.dx / 2;
	else
		line.err = -line.dy / 2;
	draw_line_helper(fdf, &line, p0->color);
}

static void	draw_rows(t_data *fdf, t_map *map)
{
	int		i;
	int		j;
	t_pixel	*p0;
	t_pixel	*p1;

	i = 0;
	while (i < map->i)
	{
		p0 = map->pixels[i];
		if (i != map->i - 1)
			p1 = map->pixels[i + 1];
		if (p0->row != p1->row)
		{
			i += 1;
			continue ;
		}
		draw_line(fdf, p0, p1, map);
		i += 1;
	}
}

static void	draw_cols(t_data *fdf, t_map *map)
{
	int		i;
	int		j;
	t_pixel	*p0;
	t_pixel	*p1;

	i = 0;
	while (i < map->i)
	{
		p0 = map->pixels[i];
		if (!map->pixels[i + map->col])
			break ;
		if (i != map->i - map->col)
			p1 = map->pixels[i + map->col];
		if (p0->col != p1->col)
		{
			i += 1;
			continue ;
		}
		draw_line(fdf, p0, p1, map);
		i += 1;
	}
}

void	map_draw(t_data *fdf, t_map *map)
{
	int		i;
	int		j;

	map->ofs_y = map->ofs_y_mv;
	map->ofs_x = map->ofs_x_mv;
	draw_rows(fdf, map);
	draw_cols(fdf, map);
	map->ofs_x += map->unit;
	map->ofs_y += map->unit;
}
