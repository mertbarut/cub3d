/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:09:37 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 18:27:00 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_viewmodel(int x, int y, t_data *cub)
{
	t_img	*viewmodel;

	viewmodel = cub->img_coffee;
	if (x >= (SCREEN_W - viewmodel->width) / 2
		&& x < (SCREEN_W + viewmodel->width) / 2
		&& y >= SCREEN_H - viewmodel->height
		&& y < SCREEN_H)
	{
		if (viewmodel->data[viewmodel->i++] != TRANSPARENT)
			cub->buffer[y][x] = viewmodel->data[viewmodel->i - 1];
		if (viewmodel->i / (viewmodel->width * viewmodel->height))
			viewmodel->i = 0;
	}
}

void	draw_buffer(t_data *cub)
{
	t_img	*frame;
	int		x;
	int		y;

	frame = cub->frame;
	y = 0;
	while (y < cub->height)
	{
		x = 0;
		while (x < cub->width)
		{
			draw_viewmodel(x, y, cub);
			frame->data[y * cub->width + x] = cub->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, frame->img, 0, 0);
}
