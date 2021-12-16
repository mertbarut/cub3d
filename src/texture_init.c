/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:12:28 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/16 14:20:49 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

extern uint32_t  texture[8][TEX_W * TEX_H];
extern uint32_t  buffer[TEX_H][TEX_W];

void	texture_init_helper(int x, int y, t_texture *t)
{
	int	i;

	i = t->width * y + x;
	t->color_xor = (x * 256 / t->width) ^ (y * 256 / t->height);
	//t->color_x = x * 256 / t->width;
	t->color_y = y * 256 / t->height;
	t->color_xy = y * 128 / t->height + x * 128 / t->width;
	texture[0][i] = 65536 * 254 * (x != y && x != t->width - y); //flat red texture with black cross
	texture[1][i] = t->color_xy + 256 * t->color_xy + 65536 * t->color_xy; //sloped greyscale
	texture[2][i] = 256 * t->color_xy + 65536 * t->color_xy; //sloped yellow gradient
	texture[3][i] = t->color_xor + 256 * t->color_xor + 65536 * t->color_xor; //xor greyscale
	texture[4][i] = 256 * t->color_xor; //xor green
	texture[5][i] = 65536 * 192 * (x % 16 && y % 16); //red bricks
	texture[6][i] = 65536 * t->color_y; //red gradient
	texture[7][i] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
}

/* Texture generator */
void	texture_init(t_data *cub, t_texture *t)
{
	int			x;
	int			y;

	cub->texture = t;
	t->height = TEX_H;
	t->width = TEX_W;
	x = 0;
	while (x < t->width)
	{
		y = 0;
		while (y < t->height)
		{
			texture_init_helper(x, y, t);
			y++;
		}
		x++;
	}
}
