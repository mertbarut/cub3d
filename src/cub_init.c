/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:51:03 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/04 13:08:53 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	buffer_init(t_data *cub)
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

void	cub_init(t_data *cub)
{
	cub->height = SCREEN_H;
	cub->width = SCREEN_W;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		cub_exit(cub, "Error:\nmlx_init() failed\n", EXIT_FAILURE);
	cub->win = mlx_new_window(cub->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!cub->win)
		cub_exit(cub, "Error:\nmlx_new_window() failed\n", EXIT_FAILURE);
	buffer_init(cub);
	cub->start = 0;
	cub->boot = 0;
	cub->frame = NULL;
	cub->img_side_n = NULL;
	cub->img_side_s = NULL;
	cub->img_side_e = NULL;
	cub->img_side_w = NULL;
	cub->logo = NULL;
	cub->img_coffee = NULL;
	cub->menu = NULL;
}
