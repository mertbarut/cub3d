/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:12:28 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/17 23:20:50 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	texture_generate(int x, int y, t_texture *t)
{
	int	i;

	i = t->width * y + x;
	t->color_x = x * 0x100 / t->width;
	t->color_xor = t->color_x ^ (y * 0x100 / t->height);
	t->color_y = y * 0x100 / t->height;
	t->color_xy = y * 0x80 / t->height + x * 0x80 / t->width;
	t->container[0][i] = 0x10000 * 0xFE * (x != y && x != t->width - y); //flat red texture with black cross
	t->container[1][i] = t->color_xy + 0x100 * t->color_xy + 0x10000 * t->color_xy; //sloped greyscale
	t->container[2][i] = 0x100 * t->color_xy + 0x10000 * t->color_xy; //sloped yellow gradient
	t->container[3][i] = t->color_xor + 0x100 * t->color_xor + 0x10000 * t->color_xor; //xor greyscale
	t->container[4][i] = 0x100 * t->color_xor; //xor green
	t->container[5][i] = 0x10000 * 0xC0 * (x % 0x10 && y % 0x10); //red bricks
	t->container[6][i] = 0x10000 * t->color_y; //red gradient
	t->container[7][i] = 0x808080; //flat grey texture
}

/* Texture generator */
void	texture_init(t_data *cub, t_texture *t)
{
	int			x;
	int			y;

	t->count = 0;
	cub->texture = t;
	t->height = TEX_H;
	t->width = TEX_W;	
	x = 0;
	while (x < t->width)
	{
		y = 0;
		while (y < t->height)
		{
			texture_generate(x, y, t);
			y++;
		}
		x++;
	}
}
