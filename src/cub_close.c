/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:45:07 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 23:23:22 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cub_close(int keycode, t_data *cub)
{
	if (keycode == 0xFF1B)
	{
		//map_reset(cub);
		//pixels_free(&cub->map);
		mlx_destroy_image(cub->mlx, cub->img);
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
