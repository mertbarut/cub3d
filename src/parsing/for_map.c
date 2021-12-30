/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:04:14 by dmylonas          #+#    #+#             */
/*   Updated: 2021/12/30 20:11:26 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

//if there's a char besides the allowed
//or if there's a second player it's error
static
int	is_valid_char(t_data *cub, char c, int *player)
{
	if (ft_strchr("01 NSEW", c))
	{
		if (ft_isalpha(c))
		{
			if (*player)
				return (0);
			cub->player_dir = c;
			*player = 1;
		}
		return (1);
	}
	return (0);
}

void	check_map(t_data *cub)
{
	int	i;

	if (cub->player_dir == '\0')
		error_handl(cub, 7);
	i = 0;
	while (i < cub->max_row_length)
	{
		if ((cub->map[0][i] == 0) || (cub->map[cub->total_rows - 1][i] == 0))
			error_handl(cub, 5);
		i++;
	}
	i = 0;
	while (i < cub->total_rows)
	{
		if ((cub->map[i][0] == 0)
		|| (cub->map[i][cub->max_row_length - 1] == 0))
			error_handl(cub, 5);
		i++;
	}
	check_neighb_to_spaces(cub);
}

static
void	fill_row_extra(t_data *cub, int *player, int index, int col)
{
	if (!(is_valid_char(cub, cub->line[col], player)))
	{
		error_handl(cub, 4);
	}
	if (ft_isalpha(cub->line[col]))
	{
		cub->player_x = index;
		cub->player_y = col;
		cub->line[col] = '0';
	}
	while (cub->line[col] == ' ')
	{
		cub->map[index][col] = 2;
		col++;
	}
	cub->map[index][col] = cub->line[col] - 48;
}

static
void	fill_row(t_data *cub, int index, int *player)
{
	int		col;

	col = cub->max_row_length;
	cub->map[index] = (int *)malloc((col + 1) * sizeof(int));
	col = 0;
	while (cub->line[col] != '\0')
	{
		fill_row_extra(cub, player, index, col);
		col++;
	}
	while (col < cub->max_row_length)
	{
		cub->map[index][col] = 1;
		col++;
	}
}

void	fill_map(t_data *cub, int fd)
{
	int				player;
	int				start_map;
	int				row;

	row = 0;
	player = 0;
	start_map = 0;
	while (get_next_line(fd, &cub->line))
	{
		if (((*cub->line == '1') || (*cub->line == ' ')))
		{
			start_map = 1;
			fill_row(cub, row, &player);
			row++;
			if (row == cub->total_rows)
				start_map = 0;
		}
		free_double((void **)&cub->line);
	}
}
