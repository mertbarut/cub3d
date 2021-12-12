/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:58:27 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 14:13:29 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hex_convert_helper(const char *str)
{
	int	result;
	int	multiplier;
	int	buffer;
	int	i;

	result = 0;
	i = ft_strlen(str) - 1;
	buffer = 0;
	multiplier = 1;
	while (i > 0)
	{
		buffer = str[i] % 48;
		if (str[i] >= '0' && str[i] <= '9')
			result += buffer * multiplier;
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += (buffer - 7) * multiplier;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += (buffer + 9) * multiplier;
		multiplier *= 16;
		i--;
	}
	return (result);
}

static int	hex_convert(const char *str)
{
	if (!str)
		return (0x0033FF33);
	if (ft_strncmp(str, "0x", 2) == 0 || ft_strncmp(str, "0X", 2) == 0)
		return (hex_convert_helper(str));
}

static void	fdf_map_helper(t_gnl *gnl, t_pixel **pixels, t_map *map, int i)
{
	int		height;
	int		color;
	int		j;
	char	**split_comma;

	j = 0;
	while (j < map->col)
	{
		split_comma = ft_split(gnl->points[i][j], ',');
		height = ft_atoi(split_comma[0]);
		color = hex_convert(split_comma[1]);
		pixels[map->i] = pixel_new(j++, i, height, color);
		pixels[map->i]->y -= 2 * (pixels[map->i]->z) / (double)map->unit;
		map->i += 1;
		ft_split_free(split_comma, map->col + 1);
	}
}

void	fdf_map(t_gnl *gnl, t_pixel **pixels, t_map *map)
{
	int		i;
	char	**split_space;

	i = 0;
	map->i = 0;
	while (i < map->row)
	{
		split_space = gnl->points[i];
		fdf_map_helper(gnl, pixels, map, i);
		ft_split_free(split_space, map->col - 1);
		i++;
	}
	map->pixels = pixels;
}
