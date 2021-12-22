/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:09:37 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/22 16:15:42 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	cub_draw_helper(t_data *cub, t_line *line, int color)
{
	while (1)
	{
		mlx_pixel_put(cub->mlx, cub->win, line->x0, line->y0, color);
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

/* algorithm for any two pixels */
void	cub_draw(t_data *cub, t_pixel *p0, t_pixel *p1, int color)
{
	t_line	line;

	line.x0 = (p0->x);
	line.y0 = (p0->y);
	line.x1 = (p1->x);
	line.y1 = (p1->y);
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
	cub_draw_helper(cub, &line, color);
}

/* algorithm for only vertically same pixels, faster */
void	vertical_line(t_data *cub, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
		y++;
	}
}

/* algorithm for drawing a buffer onto window */
void	draw_buffer(t_data *cub)
{
	t_img	*frame;
	int	x;
	int	y;

	frame = cub->frame;
	y = 0;
	while (y < cub->height)
	{
		x = 0;
		while (x < cub->width)
		{
			frame->data[y * cub->width + x] = cub->buffer[y][x];
			//cub->buffer[y][x] = 0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, frame->img, 0, 0);
	//mlx_string_put(cub->mlx, cub->win, 10, 10, 0x000000, "TEST");
	//mlx_put_image_to_window(cub->mlx, cub->win, cub->img2->img, 5 * SCREEN_W / 6,  5 * SCREEN_H / 6);
}
