/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:55:04 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/27 17:34:49 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_render(t_data *fdf)
{
	t_map	*map;

	map = &fdf->map;
	map_draw(fdf, map);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
