/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:03:50 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/03 12:21:12 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_map(t_data *cub)
{
	int	i;

	i = 0;
	if (cub->file->map)
	{
		while ((i < cub->file->n_rows) && (cub->file->map[i]))
		{
			free(cub->file->map[i]);
			i++;
		}
		free(cub->file->map);
	}
}

static void	free_paths(t_data *cub)
{
	if (cub->file->path[NORTH])
		free(cub->file->path[NORTH]);
	if (cub->file->path[EAST])
		free(cub->file->path[EAST]);
	if (cub->file->path[WEST])
		free(cub->file->path[WEST]);
	if (cub->file->path[SOUTH])
		free(cub->file->path[SOUTH]);
}

static void	cub_clear_mlx(t_data *cub)
{
	mlx_destroy_image(cub->mlx, cub->frame->img);
	mlx_destroy_image(cub->mlx, cub->img_side_n->img);
	mlx_destroy_image(cub->mlx, cub->img_side_s->img);
	mlx_destroy_image(cub->mlx, cub->img_side_e->img);
	mlx_destroy_image(cub->mlx, cub->img_side_w->img);
	mlx_destroy_image(cub->mlx, cub->logo->img);
	mlx_destroy_image(cub->mlx, cub->menu->img);
	mlx_destroy_image(cub->mlx, cub->img_coffee->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
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
	if (cub->img_side_s)
		free(cub->img_side_s);
	if (cub->img_side_e)
		free(cub->img_side_e);
	if (cub->img_side_w)
		free(cub->img_side_w);
	if (cub->logo)
		free(cub->logo);
	if (cub->img_coffee)
		free(cub->menu);
	if (cub->menu)
		free(cub->img_coffee);
	if (str)
		ft_putstr_fd(str, STDOUT_FILENO);
	free_map(cub);
	free_paths(cub);
	exit(EXIT_SUCCESS);
}
