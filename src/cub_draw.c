/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:09:37 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 23:31:08 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	cub_draw_helper(t_data *cub, t_line *line, int color)
{
	while (1)
	{
		pixel_put(cub, line->x0, line->y0, color);
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

void	cub_draw(t_data *cub, t_pixel *p0, t_pixel *p1)
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
	cub_draw_helper(cub, &line, p0->color);
}
