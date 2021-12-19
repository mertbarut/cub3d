/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:00:55 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/19 12:26:26 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

extern int map[24][24];

static void	player_move_handle(int key, t_data *cub) // last argument will have to be changed to a pointer
{
	t_player	*p;
	double		tmp_pln_x;
	double		tmp_dir_x;

	p = cub->player;
	if (key == 'w' || key == 'W')
	{
		if (!map[(int)(p->pos.x + p->dir.x * p->speed_move)][(int)(p->pos.y)])
			p->pos.x += p->dir.x * p->speed_move;
		if (!map[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y * p->speed_move)])
			p->pos.y += p->dir.y * p->speed_move;
		mlx_clear_window(cub->mlx, cub->win);
	}
	else if (key == 's' || key == 'S')
	{
		if (!map[(int)(p->pos.x - p->dir.x * p->speed_move)][(int)(p->pos.y)])
			p->pos.x -= p->dir.x * p->speed_move;
		if (!map[(int)(p->pos.x)][(int)(p->pos.y - p->dir.y * p->speed_move)])
			p->pos.y -= p->dir.y * p->speed_move;
		mlx_clear_window(cub->mlx, cub->win);
	}
	else if (key == 'd' || key == 'D')
	{
		if (!map[(int)(p->pos.x + p->pln.x * p->speed_move)][(int)(p->pos.y)])
			p->pos.x += p->pln.x * p->speed_move;
		if (!map[(int)(p->pos.x)][(int)(p->pos.y + p->pln.y * p->speed_move)])
			p->pos.y += p->pln.y * p->speed_move;
		mlx_clear_window(cub->mlx, cub->win);
	}
	else if (key == 'a' || key == 'A')
	{
		if (!map[(int)(p->pos.x - p->pln.x * p->speed_move)][(int)(p->pos.y)])
			p->pos.x -= p->pln.x * p->speed_move;
		if (!map[(int)(p->pos.x)][(int)(p->pos.y - p->pln.y * p->speed_move)])
			p->pos.y -= p->pln.y * p->speed_move;
		mlx_clear_window(cub->mlx, cub->win);
	}
	else if (key == 'e' || key == 'E')
	{
		tmp_dir_x = p->dir.x;
		p->dir.x = p->dir.x * cos(-p->speed_rotate) - p->dir.y * sin(-p->speed_rotate);
		p->dir.y = tmp_dir_x * sin(-p->speed_rotate) + p->dir.y * cos(-p->speed_rotate);
		double tmp_dir_x = p->pln.x;
		p->pln.x = p->pln.x * cos(-p->speed_rotate) - p->pln.y * sin(-p->speed_rotate);
		p->pln.y = tmp_dir_x * sin(-p->speed_rotate) + p->pln.y * cos(-p->speed_rotate);
		mlx_clear_window(cub->mlx, cub->win);
	}
	else if (key == 'q' || key == 'Q')
	{
		tmp_dir_x = p->dir.x;
		p->dir.x = p->dir.x * cos(p->speed_rotate) - p->dir.y * sin(p->speed_rotate);
		p->dir.y = tmp_dir_x * sin(p->speed_rotate) + p->dir.y * cos(p->speed_rotate);
		tmp_dir_x = p->pln.x;
		p->pln.x = p->pln.x * cos(p->speed_rotate) - p->pln.y * sin(p->speed_rotate);
		p->pln.y = tmp_dir_x * sin(p->speed_rotate) + p->pln.y * cos(p->speed_rotate);
		mlx_clear_window(cub->mlx, cub->win);
	}
}

void	cub_exit(t_data *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	mlx_destroy_image(cub->mlx, cub->frame->img);
	mlx_destroy_image(cub->mlx, cub->img2->img);
	mlx_destroy_image(cub->mlx, cub->logo->img);
	mlx_destroy_image(cub->mlx, cub->menu->img);
	free(cub->mlx);
	free(cub->frame);
	free(cub->img2);
	free(cub->logo);
	free(cub->menu);
	exit(EXIT_SUCCESS);
}

int		cub_key(int key, t_data *cub)
{
	if (key == ' ')
		cub->start = 1;
	if (key == 'w' || key == 's' || key == 'e' || key == 'q'
		|| key == 'W' || key == 'S' || key == 'E' || key == 'Q'
		|| key == 'a' || key == 'A' || key == 'd' || key == 'D')
		player_move_handle(key, cub);
	else if (key == 0xFF1B)
		cub_exit(cub);
	return (0);
}
