/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:00:55 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/13 01:46:02 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

static void	player_move_handle(int key, t_data *cub) // last argument will have to be changed to a pointer
{
	int x;
	int y;

	if (key == 'w' || key == 'W') // move forward if no wall in front of player
	{
		printf("W\n");
		x = (int)(cub->player->pos.x + cub->player->dir.x);
		y = (int)cub->player->pos.y;
		if (x > 0 && x < 24 && y > 0 && y < 24)
			cub->player->pos.x += cub->player->dir.x;
		x = (int)cub->player->pos.x;
		y = (int)(cub->player->pos.y + cub->player->dir.y);
		if (x > 0 && x < 24 && y > 0 && y < 24)
			cub->player->pos.y += cub->player->dir.y;
	}
	else if (key == 's' || key == 'S')
	{
		printf("S\n");
		x = (int)(cub->player->pos.x - cub->player->dir.x);
		y = (int)cub->player->pos.y;
		if (x > 0 && x < 24 && y > 0 && y < 24)
			cub->player->pos.x -= cub->player->dir.x;
		x = (int)cub->player->pos.x;
		y = (int)(cub->player->pos.y - cub->player->dir.y);
		if (x > 0 && x < 24 && y > 0 && y < 24)
			cub->player->pos.y -= cub->player->dir.y;
	}
	else if (key == 'd' || key == 'D')
	{
		printf("D\n");

		double old_dir_x = cub->player->dir.x;
		cub->player->dir.x = cub->player->dir.x * cos(-45) - cub->player->dir.y * sin(-45);
		cub->player->dir.y = old_dir_x * sin(-45) + cub->player->dir.y * cos(-45);
		double old_plane_x = cub->player->pln.x;
		cub->player->pln.x = cub->player->pln.x * cos(-45) - cub->player->pln.y * sin(-45);
		cub->player->pln.y = old_plane_x * sin(-45) + cub->player->pln.y * cos(-45);
	}
	else if (key == 'a' || key == 'A')
	{
		printf("A\n");
	}
}

int		player_move(int key, t_data *cub)
{
	if (key == 'w' || key == 'a' || key == 's' || key == 'd'
	|| key == 'W' || key == 'A' || key == 'S' || key == 'D')
	{
		player_move_handle(key, cub);
	}
	return(0);
}
