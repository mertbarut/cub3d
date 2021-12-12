/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:00:55 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/28 15:40:13 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	map_limiter(t_data *fdf)
{
	t_map	*map;

	map = &fdf->map;
	if (map->unit > 30)
		map->unit = 30;
	if (map->unit <= 0)
		map->unit = 1;
}

static int	map_move_handle(int key, t_data *fdf)
{
	t_map	*map;

	map = &fdf->map;
	if (key == 'w')
		map->ofs_x_mv += map->sens;
	else if (key == 's')
		map->ofs_x_mv -= map->sens;
	else if (key == 'd')
		map->ofs_y_mv += map->sens;
	else if (key == 'a')
		map->ofs_y_mv -= map->sens;
	else if (key == 'e')
		map->unit += 1;
	else if (key == 'q')
		map->unit -= 1;
	map_limiter(fdf);
}

int	map_move(int key, t_data *fdf)
{
	if (key == 'w' || key == 'a' || key == 's' || key == 'd'
		|| key == 'e' || key == 'q')
	{
		map_reset(fdf);
		map_move_handle(key, fdf);
		fdf_init(fdf);
	}
}
