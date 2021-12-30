/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:04:17 by dmylonas          #+#    #+#             */
/*   Updated: 2021/12/30 19:19:14 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static
void	print_2d_map(t_data *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->total_rows)
	{
		j = 0;
		while (j < cub->max_row_length)
		{
			if (cub->map[i][j] == 0)
				printf(" ");
			else
				printf("%d", cub->map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	error_handl(t_data *cub, int signal)
{
	printf("\x1B[31mError\n");
	if (signal == -1)
		printf("Setting file misconfigured\n");
	else if (signal == 0)
		printf("Setting file couldn't open\n");
	else if (signal == 1)
		printf("A texture was given more than once\n");
	else if (signal == 2)
		printf("Color for ceiling or floor misconfig\n");
	else if (signal == 3)
		printf("Color out of range\n");
	else if (signal == 4)
		printf("Map can only contain 0, 1 and ONLY one NSWE\n");
	else if (signal == 5)
		printf("Map borders should be 1\n");
	else if (signal == 6)
		printf("Invalid wall texture path\n");
	else if (signal == 7)
		printf("Map should contain N or W or S or E\n");
	exit (signal);
}

void	free_double(void **to_free)
{
	if (*to_free)
		free(*to_free);
	*to_free = NULL;
}

static
void	parsing_init(t_data *cub)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		cub->path[i] = '\0';
		cub->rgb_floor[i] = -1;
		cub->rgb_ceiling[i] = -1;
		i++;
	}
	cub->path[3] = '\0';
	cub->fcolor = -1;
	cub->ccolor = -1;
	cub->player_dir = '\0';
	cub->player_x = 0;
	cub->player_y = 0;
	cub->max_row_length = 0;
	cub->total_rows = 0;
}

void	parsing(t_data *cub, char *file_path)
{
	int	fd;

	parsing_init(cub);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_handl(cub, 0);
	while (get_next_line(fd, &cub->line))
	{
		parse_settings(cub, cub->line);
		free_double((void **)&cub->line);
	}
	close(fd);
	color_check_and_final(cub);
	fd = open(file_path, O_RDONLY);
	cub->map = (int **)malloc((cub->total_rows + 1) * sizeof(int *));
	fill_map(cub, fd);
	close(fd);
	print_2d_map(cub);
	check_map(cub);
}
