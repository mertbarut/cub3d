/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:06:13 by dmylonas          #+#    #+#             */
/*   Updated: 2021/12/30 19:59:23 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static
void	find_max_row_len(t_data *cub, char *line)
{
	int	line_size;

	line_size = ft_strlen(line);
	if (line_size > cub->max_row_length)
		cub->max_row_length = line_size;
	cub->total_rows++;
}

static
void	parse_path(t_data *cub, char **texture_path, char *line)
{
	if (*texture_path)
		error_handl(cub, 1);
	*texture_path = ft_strtrim(line, " ");
}

static
int	are_settings_set(t_data *cub)
{
	if ((cub->rgb_floor[2] == -1) || (cub->rgb_ceiling[2] == -1))
		return (0);
	if (!(cub->path[NORTH]) || !(cub->path[SOUTH]))
		return (0);
	if (!(cub->path[EAST]) || !(cub->path[WEST]))
		return (0);
	return (1);
}

//it's for the texture and for the colors
//and also finds the biggest row in the map
void	parse_settings(t_data *cub, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_path(cub, &cub->path[NORTH], line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_path(cub, &cub->path[EAST], line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_path(cub, &cub->path[SOUTH], line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_path(cub, &cub->path[WEST], line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_colors(cub, cub->rgb_floor, (line + 2));
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_colors(cub, cub->rgb_ceiling, (line + 2));
	else if (((*line == '1') || (*line == ' ')) && ((are_settings_set(cub))))
		find_max_row_len(cub, line);
	else if (*line != '\0')
		error_handl(cub, -1);
}
