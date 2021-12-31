/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:11:27 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 17:50:51 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	player_face_x(t_data *cub, t_player *player)
{
	if (cub->file->flag_player_direction == 'E')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->pln.x = ((double)PLAYER_FOV * -1) / 100;
		player->pln.y = 0;
	}
	else if (cub->file->flag_player_direction == 'W')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->pln.x = ((double)PLAYER_FOV * 1) / 100;
		player->pln.y = 0;
	}
}

static void	player_face_y(t_data *cub, t_player *player)
{
	if (cub->file->flag_player_direction == 'N')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->pln.x = 0;
		player->pln.y = ((double)PLAYER_FOV * -1) / 100;
	}
	else if (cub->file->flag_player_direction == 'S')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->pln.x = 0;
		player->pln.y = ((double)PLAYER_FOV * 1) / 100;
	}
}

void	player_init(t_data *cub, t_player *player)
{
	player_face_x(cub, player);
	player_face_y(cub, player);
	player->speed_move = PLAYER_MOVE_SPEED;
	player->speed_rotate = PLAYER_ROTATE_SPEED;
}
