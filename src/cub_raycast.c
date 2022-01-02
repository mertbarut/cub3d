/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:08:43 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/02 14:28:05 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycasting_calc(t_ray *ray, t_player *p)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = LEFT;
		ray->side_dist.x = (p->pos.x - ray->tile_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = RIGHT;
		ray->side_dist.x = (ray->tile_x + 1.0 - p->pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = DOWN;
		ray->side_dist.y = (p->pos.y - ray->tile_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = UP;
		ray->side_dist.y = (ray->tile_y + 1.0 - p->pos.y) * ray->delta_dist.y;
	}
}

void	raycasting_send(t_data *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->tile_x += ray->step_x;
			ray->side = EAST + WEST;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->tile_y += ray->step_y;
			ray->side = NORTH + SOUTH;
		}
		if (cub->file->map[ray->tile_x][ray->tile_y] > 0)
			ray->hit = 1;
	}
}

void	raycasting_setpixel(int x, t_ray *ray, t_player *p)
{
	ray->draw_start.x = x;
	ray->draw_end.x = x;
	if (ray->side == EAST + WEST)
		ray->pwd = (ray->tile_x - p->pos.x + (1.0 - ray->step_x) / 2)
			/ ray->dir.x;
	else
		ray->pwd = (ray->tile_y - p->pos.y + (1.0 - ray->step_y) / 2)
			/ ray->dir.y;
	if (ray->pwd < MIN_PWD)
		ray->pwd = MIN_PWD;
	ray->line_height = (int)(SCREEN_H / ray->pwd);
	ray->draw_start.y = (int)(-ray->line_height / 2 + SCREEN_H / 2);
	ray->draw_end.y = (int)(ray->line_height / 2 + SCREEN_H / 2);
	if (ray->draw_start.y < 0)
		ray->draw_start.y = 0;
	if (ray->draw_end.y >= SCREEN_H)
		ray->draw_end.y = SCREEN_H - 1;
}

void	raycasting_texture_getpos(t_texture *t, t_ray *ray, t_player *p)
	{
	if (ray->side == EAST + WEST)
		ray->wall_x = p->pos.y + ray->pwd * ray->dir.y;
	else
		ray->wall_x = p->pos.x + ray->pwd * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->texture_x = (int)(ray->wall_x * (double)(t->width));
	if (ray->side == EAST + WEST)
	{
		if (ray->dir.x > 0)
			ray->texture_i = west;
		else
			ray->texture_i = east;
	}
	else
	{
		if (ray->dir.y < 0)
			ray->texture_i = south;
		else
			ray->texture_i = north;
	}
}

void	raycasting_texture_setcol(int x, t_texture *t, t_ray *ray, t_data *cub)
{
	int	y;
	int	color;
	int	top;
	int	bottom;

	y = ray->draw_start.y;
	t->step = 1.0 * t->height / ray->line_height;
	t->pos = (y - (double)SCREEN_H / 2 + (double)ray->line_height / 2)
		* t->step;
	top = 0;
	while (top < y)
		cub->buffer[top++][x] = cub->color_ceiling;
	while (y < ray->draw_end.y)
	{
		ray->texture_y = (int)t->pos & (t->height - 1);
		t->pos += t->step;
		color = t->container[ray->texture_i]
		[t->height * ray->texture_y + ray->texture_x];
		cub->buffer[y][x] = color;
		y++;
	}
	bottom = y;
	while (bottom < SCREEN_H)
		cub->buffer[bottom++][x] = cub->color_floor;
}
