/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:21:54 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/27 19:46:07 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixels_free(t_map *map)
{
	int	i;

	i = map->i;
	while (i >= 0)
		free(map->pixels[i--]);
	free(map->pixels);
}
