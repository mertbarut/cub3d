/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:55:04 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/13 23:34:33 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

extern	int	map[24][24];

void	raycasting_init(int x, t_ray *ray, t_player *player)
{
	ray->hit = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->cam_x = 2 * x / (double)SCREEN_W - 1;
	ray->dir.x = player->dir.x + player->pln.x * ray->cam_x;
	ray->dir.y = player->dir.y + player->pln.y * ray->cam_x;
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

void	raycasting_calc(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (player->pos.x - ray->tile_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->tile_x + 1.0 - player->pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (player->pos.y - ray->tile_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->tile_y + 1.0 - player->pos.y) * ray->delta_dist.y;
	}
}

void	raycasting_send(t_ray *ray, t_player *player)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->tile_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->tile_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->tile_x][ray->tile_y] > 0)
			ray->hit = 1;
	}
}

void	raycasting_setpixel(int x, t_ray *ray, t_player *player)
{
	double	perp_wall_dist;
	int		line_height;
	
	ray->draw_start.x = x;
	ray->draw_end.x = x;
    if (ray->side == 0)
		perp_wall_dist = (ray->tile_x - player->pos.x + (1 - ray->step_x) / 2) / ray->dir.x;
    else
		perp_wall_dist = (ray->tile_y - player->pos.y + (1 - ray->step_y) / 2) / ray->dir.y;
	line_height = (int)(SCREEN_H / perp_wall_dist);
	ray->draw_start.y = (int)(-line_height / 2 + SCREEN_H / 2);
	ray->draw_end.y = (int)(line_height / 2 + SCREEN_H / 2);
	if (ray->draw_start.y < 0)
		ray->draw_start.y = 0;
	if (ray->draw_end.y >= SCREEN_H)
		ray->draw_end.y = SCREEN_H - 1;
}

void	raycasting_setcolor(t_ray *ray, t_player *player)
{
	if (map[ray->tile_x][ray->tile_y] == 1)
		ray->color = 0xde3163;
	else if (map[ray->tile_x][ray->tile_y] == 2)
		ray->color = 0x9fe2bf;
	else if (map[ray->tile_x][ray->tile_y] == 3)
		ray->color = 0x6495ed;
	else if (map[ray->tile_x][ray->tile_y] == 4)
		ray->color = 0xffffff;
	else
		ray->color = 0xdfff00;
	if (ray->side == 1)
		ray->color = ray->color / 2;
}

void	raycasting_basic(t_data *cub)
{
	t_ray		ray;
	t_player	*player;
	int	x;

	player = cub->player;
	x = 0;
	while (x < SCREEN_W)
	{
		raycasting_init(x, &ray, player);
		raycasting_calc(&ray, player);
		raycasting_send(&ray, player);
		raycasting_setpixel(x, &ray, player);
		raycasting_setcolor(&ray, player);
		vertical_line(cub, x, ray.draw_start.y, ray.draw_end.y, ray.color);
    	//cub_draw(cub, &ray.draw_start, &ray.draw_end, ray.color);
		x++;
	}
}

int		cub_render(t_data *cub)
{
	raycasting_basic(cub);
	return(0);
}
