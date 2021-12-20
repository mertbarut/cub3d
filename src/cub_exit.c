/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:03:50 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/20 18:27:49 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_clear_mlx(t_data *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	mlx_destroy_image(cub->mlx, cub->frame->img);
	mlx_destroy_image(cub->mlx, cub->img_side_n->img);
	mlx_destroy_image(cub->mlx, cub->logo->img);
	mlx_destroy_image(cub->mlx, cub->menu->img);
}

void	cub_exit(t_data *cub, char *str, int flag_mlx)
{
	if (flag_mlx)
		cub_clear_mlx(cub);
	if (cub->mlx)
		free(cub->mlx);
	if (cub->frame)
		free(cub->frame);
	if (cub->img_side_n)
		free(cub->img_side_n);
	if (cub->logo)
		free(cub->logo);
	if (cub->menu)
		free(cub->menu);
	if (str)
		ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
