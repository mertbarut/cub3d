/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_configure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:06:13 by dmylonas          #+#    #+#             */
/*   Updated: 2022/01/03 14:04:56 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	find_max_row_len(t_cubfile *f)
{
	int	n;

	n = ft_strlen(f->line);
	if (n > f->max_rows)
		f->max_rows = n;
	f->n_rows++;
}

static void	cubfile_parsepath(t_cubfile *f, t_data *cub, int direction)
{
	if (f->path[direction])
	{
		free_double((void **)&f->line);
		cubfile_error(cub, 1);
	}
	f->path[direction] = ft_strtrim(f->line + 3, " ");
}

static int	are_settings_set(t_cubfile *f)
{
	if ((f->rgb_color_floor[2] == -1) || (f->rgb_color_ceiling[2] == -1))
		return (0);
	if (!(f->path[NORTH]) || !(f->path[SOUTH]))
		return (0);
	if (!(f->path[EAST]) || !(f->path[WEST]))
		return (0);
	return (1);
}

void	cubfile_configure(t_cubfile *f, t_data *cub)
{
	if (ft_strncmp(f->line, "NO ", 3) == 0)
		cubfile_parsepath(f, cub, NORTH);
	else if (ft_strncmp(f->line, "EA ", 3) == 0)
		cubfile_parsepath(f, cub, EAST);
	else if (ft_strncmp(f->line, "SO ", 3) == 0)
		cubfile_parsepath(f, cub, SOUTH);
	else if (ft_strncmp(f->line, "WE ", 3) == 0)
		cubfile_parsepath(f, cub, WEST);
	else if (ft_strncmp(f->line, "F ", 2) == 0)
		cubfile_parsecolor(f, cub, f->rgb_color_floor);
	else if (ft_strncmp(f->line, "C ", 2) == 0)
		cubfile_parsecolor(f, cub, f->rgb_color_ceiling);
	else if ((*f->line == '1' || *f->line == ' ') && are_settings_set(f))
		find_max_row_len(f);
	else if (*f->line != '\0')
	{
		free_double((void **)&f->line);
		cubfile_error(cub, -1);
	}
}
