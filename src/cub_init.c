/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:51:03 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/02 14:24:02 by mbarut           ###   ########.fr       */
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
		cub_exit(cub, "Error: mlx_init() failed\n", 0);
	cub->win = mlx_new_window(cub->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!cub->win)
		cub_exit(cub, "Error: mlx_new_window() failed\n", 0);
	buffer_init(cub);
	cub->start = 0;
	cub->boot = 0;
}
