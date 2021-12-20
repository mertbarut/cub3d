/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:11:27 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/20 18:03:07 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_init(t_player *player, double fov, t_cubfile *cubfile)
{
	// get the position of player from read map
	// for now, assume it is fixed
	(void)cubfile;
	
	player->pos.x = 12;
	player->pos.y = 5;

	// get the initial direction of player from read map
	// for now, assume it is WEST
	
	player->dir.x = -1;
	player->dir.y = 0;

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
