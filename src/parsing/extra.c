/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:56:20 by dmylonas          #+#    #+#             */
/*   Updated: 2021/12/30 20:00:46 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_neighb_to_spaces(t_data *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->total_rows)
	{
		j = 0;
		while (j < cub->max_row_length)
		{
			if (cub->map[i][j] == 2)
			{
				if ((i + 1 < cub->total_rows) && (cub->map[i + 1][j] == 0))
					error_handl(cub, 5);
				if ((i -1 >= 0) && (cub->map[i - 1][j] == 0))
					error_handl(cub, 5);
				if ((j + 1 < cub->max_row_length) && (cub->map[i][j + 1] == 0))
					error_handl(cub, 5);
				if ((j - 1 >= 0) && (cub->map[i][j - 1] == 0))
					error_handl(cub, 5);
			}
			j++;
		}
		i++;
	}
}
