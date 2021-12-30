/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:04:19 by dmylonas          #+#    #+#             */
/*   Updated: 2021/12/30 20:03:55 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

//checks range of colors to be below 255 
//and parses the combination of rgb into one final value, fcolor and ccolor
void	color_check_and_final(t_data *cub)
{
	if (cub->rgb_floor[0] > 255 || cub->rgb_floor[1] > 255
		|| cub->rgb_floor[2] > 255)
		error_handl(cub, 3);
	if (cub->rgb_ceiling[0] > 255 || cub->rgb_ceiling[1] > 255
		|| cub->rgb_ceiling[2] > 255)
		error_handl(cub, 3);
	cub->fcolor = cub->rgb_floor[0];
	cub->fcolor = (cub->fcolor << 8) + cub->rgb_floor[1];
	cub->fcolor = (cub->fcolor << 8) + cub->rgb_floor[2];
	cub->ccolor = cub->rgb_ceiling[0];
	cub->ccolor = (cub->ccolor << 8) + cub->rgb_ceiling[1];
	cub->ccolor = (cub->ccolor << 8) + cub->rgb_ceiling[2];
}

//parses colors from file to the rgb array
void	parse_colors(t_data *cub, int rgb[3], char *line)
{
	unsigned int	number;

	while (*line)
	{
		number = 0;
		while (*line == ' ')
			line++;
		while (ft_isdigit(*line))
		{
			if (rgb[2] >= 0)
				error_handl(cub, 2);
			number = (number * 10) + (*line - '0');
			line++;
		}
		if (rgb[0] < 0)
			rgb[0] = number;
		else if (rgb[1] < 0)
			rgb[1] = number;
		else if (rgb[2] < 0)
			rgb[2] = number;
		else if ((*line))
			error_handl(cub, 2);
		if ((*line == ',') && (rgb[2] < 0))
			line++;
	}
}
