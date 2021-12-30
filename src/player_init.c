/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:11:27 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/30 16:36:26 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_init(t_data *cub, t_player *player, double fov, t_cubfile *cubfile)
{
	// get the position of player from read map
	// for now, assume it is fixed
	(void)cubfile;
	
	player->pos.x = cub->player_x;
	player->pos.y = cub->player_y;

	// get the initial direction of player from read map
	// for now, assume it is WEST
	// if (cub->player_dir == 'N')
	// {
	player->dir.x = -1;
	player->dir.y = 0;
	// }
	// //
	// else if (cub->player_dir == 'S')
	// {
		player->dir.x = 1;
		player->dir.y = 0;
	// }

	// desired fov is passed to function
	if (fov < 60 || fov > 120)
	{
		ft_putstr_fd("Error: given fov must be between 60 and 120", 2);
		exit(EXIT_FAILURE);
	}
	player->pln.x = 0;
	player->pln.y = fov / 100;
	
	// move and rotate speed
	player->speed_move = PLAYER_MOVE_SPEED;
	player->speed_rotate = PLAYER_ROTATE_SPEED;
}
