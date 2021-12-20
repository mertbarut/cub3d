/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:03:50 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/20 13:04:34 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_exit(t_data *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	mlx_destroy_image(cub->mlx, cub->frame->img);
	mlx_destroy_image(cub->mlx, cub->img2->img);
	mlx_destroy_image(cub->mlx, cub->logo->img);
	mlx_destroy_image(cub->mlx, cub->menu->img);
	free(cub->mlx);
	free(cub->frame);
	free(cub->img2);
	free(cub->logo);
	free(cub->menu);
	exit(EXIT_SUCCESS);
}
