/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:03:50 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/03 20:32:57 by mbarut           ###   ########.fr       */
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
	if (cub->frame)
		mlx_destroy_image(cub->mlx, cub->frame->img);
	if (cub->img_side_n)
		mlx_destroy_image(cub->mlx, cub->img_side_n->img);
	if (cub->img_side_s)
		mlx_destroy_image(cub->mlx, cub->img_side_s->img);
	if (cub->img_side_e)
		mlx_destroy_image(cub->mlx, cub->img_side_e->img);
	if (cub->img_side_w)
		mlx_destroy_image(cub->mlx, cub->img_side_w->img);
	if (cub->logo)
		mlx_destroy_image(cub->mlx, cub->logo->img);
	if (cub->menu)
		mlx_destroy_image(cub->mlx, cub->menu->img);
	if (cub->img_coffee)
		mlx_destroy_image(cub->mlx, cub->img_coffee->img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
}

void	cub_exit(t_data *cub, char *str, int signal)
{
	if (cub)
		cub_clear_mlx(cub);
	if (str)
		ft_putstr_fd(str, STDOUT_FILENO);
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
	if (cub->img_coffee)
		free(cub->img_coffee);
	if (cub->logo)
		free(cub->logo);
	if (cub->menu)
		free(cub->menu);
	if (cub->mlx)
		free(cub->mlx);
	free_map(cub);
	free_paths(cub);
	exit(signal);
}
