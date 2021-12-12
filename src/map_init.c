/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:35:39 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 14:14:09 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_format_n(t_gnl *gnl, t_map *map)
{
	int	n;

	n = map->n;
	ft_putstr_fd("Error: Map should have at least 1 x 1 size \n", 2);
	if (n != 0)
		ft_split_free(*(gnl->points), n);
	exit(0);
}

void	map_init(t_gnl *gnl, t_map *map)
{
	map->unit = 15;
	map->col = gnl_column_count(gnl);
	map->row = gnl->row_count;
	map->n = map->row * map->col;
	map->ofs_x = 0;
	map->ofs_y = 0;
	map->ofs_x_mv = 0;
	map->ofs_y_mv = 0;
	map->sens = 5;
	map->i = 0;
	if (map->n <= 2)
		fdf_format_n(gnl, map);
}
