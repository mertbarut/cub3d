/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:55:04 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 18:38:21 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	raycasting_init(int x, t_ray *ray, t_player *player)
{
	ray->hit = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->dir.x = player->dir.x + player->pln.x * (2 * x / (double)SCREEN_W - 1);
	ray->dir.y = player->dir.y + player->pln.y * (2 * x / (double)SCREEN_W - 1);
	ray->tile_x = (int)player->pos.x;
	ray->tile_y = (int)player->pos.y;
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

static void	raycasting(t_data *cub)
{
	t_ray		ray;
	t_player	*player;
	t_texture	*texture;
	int			x;

	player = cub->player;
	texture = cub->texture;
	x = 0;
	while (x < SCREEN_W)
	{
		raycasting_init(x, &ray, player);
		raycasting_calc(&ray, player);
		raycasting_send(cub, x, &ray, player);
		raycasting_setpixel(x, &ray, player);
		raycasting_texture_getpos(texture, &ray, player);
		raycasting_texture_setcol(x, texture, &ray, cub);
		x++;
	}
	draw_buffer(cub);
}

int	cub_render(t_data *cub)
{
	if (!cub->boot && cub_boot(cub))
		return (0);
	if (!cub->start)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->menu->img, 0, 0);
	else
		raycasting(cub);
	return (0);
}
