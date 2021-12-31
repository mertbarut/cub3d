/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:12:28 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 18:57:32 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	texture_match(t_data *cub, int x, int y, t_texture *t)
{
	int	i;

	i = t->width * y + x;
	t->container[0][i] = cub->img_side_s->data[i];
	t->container[1][i] = cub->img_side_w->data[i];
	t->container[2][i] = cub->img_side_n->data[i];
	t->container[3][i] = cub->img_side_e->data[i];
}

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
			texture_match(cub, x, y, t);
			y++;
		}
		x++;
	}
}
