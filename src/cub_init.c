/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:51:03 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/20 13:51:13 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_init(t_data *cub, t_player *player)
{
	int	i;
	int	j;

	cub->height = SCREEN_H;
	cub->width = SCREEN_W;
	cub->player = player;
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, SCREEN_W, SCREEN_H, "cub3d");
	i = 0;
	while (i < TEX_H)
	{
		j = 0;
		while (j < TEX_W)
			cub->buffer[i][j++] = 0;
		i++;
	}
	cub->start = 0;
	cub->boot = 0;
	cub->bg_color_ceiling = 0x6495ed;
	cub->bg_color_floor = 0x9fe2bf;
}
