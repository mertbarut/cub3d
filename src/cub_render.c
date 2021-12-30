/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:55:04 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/30 12:42:07 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// extern	int	map[24][24];

void	raycasting_init(int x, t_ray *ray, t_player *player)
{
	ray->hit = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->n_y = 0;
	ray->n_x = 0;
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

void	raycasting_send(t_data *cub, int x, t_ray *ray, t_player *player)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->tile_x += ray->step_x;
			ray->side = 0;
			ray->n_x++;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->tile_y += ray->step_y;
			ray->side = 1;
			ray->n_y++;
		}
		if (cub->map[ray->tile_x][ray->tile_y] > 0)
		{
			ray->hit = 1;
			//printf("ray #%d has hit a block after %d x moves and %d y moves.\n", x, ray->n_x, ray->n_y);
		}
	}
}

void	raycasting_setpixel(int x, t_ray *ray, t_player *player)
{
	ray->draw_start.x = x;
	ray->draw_end.x = x;
    if (ray->side == 0)
		ray->perp_wall_dist = (ray->tile_x - player->pos.x + (1 - ray->step_x) / 2) / ray->dir.x;
    else
		ray->perp_wall_dist = (ray->tile_y - player->pos.y + (1 - ray->step_y) / 2) / ray->dir.y;
	ray->line_height = (int)(SCREEN_H / ray->perp_wall_dist);
	ray->draw_start.y = (int)(-ray->line_height / 2 + SCREEN_H / 2);
	ray->draw_end.y = (int)(ray->line_height / 2 + SCREEN_H / 2);
	if (ray->draw_start.y < 0)
		ray->draw_start.y = 0;
	if (ray->draw_end.y >= SCREEN_H)
		ray->draw_end.y = SCREEN_H - 1;
}

/* TEXTURE */

void	raycasting_getposition_texture(t_texture *t, t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_x = player->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->perp_wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->texture_x = (int)(ray->wall_x * (double)(t->width));
	if (ray->side == 0 && ray->dir.x > 0) // SOUTH WALL
	{
		ray->texture_x = t->width - ray->texture_x - 1;
		ray->texture_i = south;
	}
	if (ray->side == 1 && ray->dir.y < 0) // WEST WALL
	{
		ray->texture_x = t->width - ray->texture_x - 1;
		ray->texture_i = west;
	}
	if (ray->side == 0 && ray->dir.x <= 0) // NORTH WALL
	{
		//ray->texture_x = t->width - ray->texture_x - 1;
		ray->texture_i = north;
	}
	if (ray->side == 1 && ray->dir.y >= 0) // EAST WALL
	{
		//ray->texture_x = t->width - ray->texture_x - 1;
		ray->texture_i = east;
	}
}

void	raycasting_setcolor_texture(int x, t_texture *t, t_ray *ray, t_data *cub)
{
	int	y;
	int color;
	int	top;
	int bottom;

	y = ray->draw_start.y;
	t->step = 1.0 * t->height / ray->line_height;
	t->pos = (y - (double)SCREEN_H / 2 + (double)ray->line_height / 2) * t->step;
	top = 0;
	while (top < y)
		cub->buffer[top++][x] = cub->bg_color_ceiling;
	while (y < ray->draw_end.y)
	{
		ray->texture_y = (int)t->pos & (t->height - 1);
		t->pos += t->step;
		color = t->container[ray->texture_i][t->height * ray->texture_y + ray->texture_x];
		// give ns sides shadow
		//if (ray->side == 1)
		//	color = (color >> 1) & 0x7F7F7F;
        cub->buffer[y][x] = color;
		y++;
	}
	bottom = y;
	while (bottom < SCREEN_H)
		cub->buffer[bottom++][x] = cub->bg_color_floor;
}

void	raycasting_find_side(t_ray *ray, t_texture *t, t_data *cub)
{
	if (ray->side == 0 && ray->dir.x > 0) // SOUTH WALL
	{
		ray->texture_x = t->width - ray->texture_x - 1;
		ray->texture_i = south;
	}
	if (ray->side == 1 && ray->dir.y < 0) // WEST WALL
	{
		ray->texture_x = t->width - ray->texture_x - 1;
		ray->texture_i = west;
	}
	if (ray->side == 0 && ray->dir.x <= 0) // NORTH WALL
	{
		//ray->texture_x = t->width - ray->texture_x - 1;
		ray->texture_i = north;
	}
	if (ray->side == 1 && ray->dir.y >= 0) // EAST WALL
	{
		//ray->texture_x = t->width - ray->texture_x - 1;
		ray->texture_i = east;
	}
}

/* /TEXTURE */

// void	raycasting_setcolor_basic(t_ray *ray, t_player *player)
// {
// 	printf("\n\n\nll\n");
// 	if (map[ray->tile_x][ray->tile_y] == 1)
// 		ray->color = 0xde3163;
// 	else if (map[ray->tile_x][ray->tile_y] == 2)
// 		ray->color = 0x9fe2bf;
// 	else if (map[ray->tile_x][ray->tile_y] == 3)
// 		ray->color = 0x6495ed;
// 	else if (map[ray->tile_x][ray->tile_y] == 4)
// 		ray->color = 0xffffff;
// 	else
// 		ray->color = 0xdfff00;
// 	if (ray->side == 1)
// 		ray->color = ray->color / 2;
// }

// void	raycasting_basic(t_data *cub)
// {
// 	t_ray		ray;
// 	t_player	*player;
// 	int	x;

// 	player = cub->player;
// 	x = 0;
// 	while (x < SCREEN_W)
// 	{
// 		raycasting_init(x, &ray, player);
// 		raycasting_calc(&ray, player);
// 		raycasting_send(x, &ray, player);
// 		raycasting_setpixel(x, &ray, player);
// 		raycasting_setcolor_basic(&ray, player);
// 		vertical_line(cub, x, ray.draw_start.y, ray.draw_end.y, ray.color);
// 		//cub_draw(cub, &ray.draw_start, &ray.draw_end, ray.color);
// 		x++;
// 	}
// }

void	whereamilookingat(int x, t_ray *ray)
{
	if (x == SCREEN_W / 2)
	{
		if (ray->side == 0 && ray->dir.x > 0)
			printf("DIRECTION: SOUTH\n");
		else if (ray->side == 1 && ray->dir.y < 0)
			printf("DIRECTION: WEST\n");
		else if (ray->side == 0 && ray->dir.x <= 0)
			printf("DIRECTION: NORTH\n");
		else if (ray->side == 1 && ray->dir.y >= 0)
			printf("DIRECTION: EAST\n");
	}
}

void	raycasting_textured(t_data *cub)
{
	t_ray		ray;
	t_player	*player;
	t_texture	*texture;
	int	x;

	player = cub->player;
	texture = cub->texture;
	x = 0;
	while (x < SCREEN_W)
	{
		raycasting_init(x, &ray, player);
		raycasting_calc(&ray, player);
		raycasting_send(cub, x, &ray, player);
		raycasting_setpixel(x, &ray, player);
		raycasting_getposition_texture(texture, &ray, player);
		raycasting_setcolor_texture(x, texture, &ray, cub);
		raycasting_find_side(&ray, texture, cub);
		//whereamilookingat(x, &ray);
		x++;
	}
	draw_buffer(cub);
}

int		cub_boot(t_data *cub, int limit)
{
	int i;
	int j;

	i = 0;
	while (i < limit)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, cub->logo->img, 0, 0);
		if (i > limit / 1.8)
		{
			j = 0;
			while (j < SCREEN_W * SCREEN_H)
			{
				if (cub->logo->data[j] > 0)
					cub->logo->data[j] = 0;
				j++;
			}
		}
		if (i == limit - 1 && ++cub->boot)
			return (1);
		i++;
	}
	return (0);
}

int		cub_render(t_data *cub)
{
	if (!cub->boot && cub_boot(cub, 2022))
		return (0);
	if (!cub->start)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->menu->img, 0, 0);
	else
		raycasting_textured(cub);
	//raycasting_basic(cub);
	return(0);
}
