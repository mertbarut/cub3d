/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:51:03 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/22 01:31:33 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	buffer_init(t_data *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < TEX_H)
	{
		j = 0;
		while (j < TEX_W)
			cub->buffer[i][j++] = 0;
		i++;
	}
}

void	cub_init(t_data *cub, t_player *player)
{
	cub->height = SCREEN_H;
	cub->width = SCREEN_W;
	cub->player = player;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		cub_exit(cub, "Error: mlx_init() failed\n", 0);
	cub->win = mlx_new_window(cub->mlx, SCREEN_W, SCREEN_H, "cub3d");
	if (!cub->win)
		cub_exit(cub, "Error: mlx_new_window() failed\n", 0);
	buffer_init(cub);
	cub->start = 0;
	cub->boot = 0;
	cub->bg_color_ceiling = 0xC9C9C9;
	cub->bg_color_floor = 0x0E3657;
}
