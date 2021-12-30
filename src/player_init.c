/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:11:27 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 00:32:31 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_face(t_data *cub, t_player *player, double fov)
{
	if (cub->player_dir == 'N')
	{
		player->dir.x = -1;
		player->dir.y = 0;

		player->pln.x = 0;
		player->pln.y = (fov * -1) / 100;
	}
	else if (cub->player_dir == 'E')
	{
		player->dir.x = 0;
		player->dir.y = 1;

		player->pln.x = (fov * -1) / 100;
		player->pln.y = 0;
	}
	else if (cub->player_dir == 'S')
	{
		player->dir.x = 1;
		player->dir.y = 0;

		player->pln.x = 0;
		player->pln.y = (fov * 1) / 100;
	}
	else if (cub->player_dir == 'W')
	{
		player->dir.x = 0;
		player->dir.y = -1;

		player->pln.x = (fov * 1) / 100;
		player->pln.y = 0;
	}
}

void	player_init(t_data *cub, t_player *player, double fov, t_cubfile *cubfile)
{
	player->pos.x = cub->player_x;
	player->pos.y = cub->player_y;

	player_face(cub, player, fov);
	
	// move and rotate speed
	player->speed_move = PLAYER_MOVE_SPEED;
	player->speed_rotate = PLAYER_ROTATE_SPEED;
}
