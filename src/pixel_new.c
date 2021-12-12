/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:02:42 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/28 15:43:40 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	*pixel_new(int col, int row, double z, int color)
{
	t_pixel	*pixel;

	pixel = malloc(sizeof(struct s_pixel));
	pixel->col = col;
	pixel->row = row;
	pixel->x = 2 * (col - row);
	pixel->y = col + row;
	pixel->z = z;
	pixel->color = color;
}
