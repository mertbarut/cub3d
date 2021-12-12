/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:10:49 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/28 15:57:16 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *fdf, int x, int y, int color)
{
	char	*dst;

	if (y + fdf->center_y > fdf->height || y + fdf->center_y < 0
		|| x + fdf->center_x > fdf->width || x + fdf->center_x < 0)
		return ;
	dst = fdf->addr + ((y + fdf->center_y) * fdf->len
			+ (x + fdf->center_x) * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}
