/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:51:03 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/28 12:48:34 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_data *fdf)
{
	int	offset_width;
	int	offset_height;

	offset_width = 2 * (fdf->map.col - fdf->map.row) * fdf->map.unit;
	offset_height = (fdf->map.row + fdf->map.col) * fdf->map.unit;
	fdf->height = 1080;
	fdf->width = 1920;
	fdf->center_x = (fdf->width - offset_width) / 2;
	fdf->center_y = (fdf->height - offset_height) / 2;
}
