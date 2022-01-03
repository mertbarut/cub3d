/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_parsecolor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:04:19 by dmylonas          #+#    #+#             */
/*   Updated: 2022/01/03 14:27:07 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cubfile_setcolor(t_data *cub)
{
	t_cubfile	*f;

	f = cub->file;
	if (f->rgb_color_floor[0] > 255 || f->rgb_color_floor[1] > 255
		|| f->rgb_color_floor[2] > 255)
		cubfile_error(cub, 3);
	if (f->rgb_color_ceiling[0] > 255 || f->rgb_color_ceiling[1] > 255
		|| f->rgb_color_ceiling[2] > 255)
		cubfile_error(cub, 3);
	cub->color_floor = f->rgb_color_floor[0];
	cub->color_floor = (cub->color_floor << 8) + f->rgb_color_floor[1];
	cub->color_floor = (cub->color_floor << 8) + f->rgb_color_floor[2];
	cub->color_ceiling = f->rgb_color_ceiling[0];
	cub->color_ceiling = (cub->color_ceiling << 8) + f->rgb_color_floor[1];
	cub->color_ceiling = (cub->color_ceiling << 8) + f->rgb_color_floor[2];
}

static
void	cubfile_setrgb(t_data *cub, char *line, unsigned int number, int rgb[3])
{
	if (rgb[0] < 0)
		rgb[0] = number;
	else if (rgb[1] < 0)
		rgb[1] = number;
	else if (rgb[2] < 0)
		rgb[2] = number;
	else if (*line)
		cubfile_error(cub, 2);
}

void	cubfile_parsecolor(t_cubfile *f, t_data *cub, int rgb[3])
{
	unsigned int	number;
	char			*line;

	line = f->line + 2;
	while (*line)
	{
		number = 0;
		while (*line == ' ')
			line++;
		while (ft_isdigit(*line))
		{
			if (rgb[2] >= 0)
				cubfile_error(cub, 2);
			number = (number * 10) + (*line - '0');
			line++;
		}
		cubfile_setrgb(cub, line, number, rgb);
		if (*line == ',' && rgb[2] < 0)
			line++;
	}
}
