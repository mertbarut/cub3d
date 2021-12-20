/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:00:55 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/20 18:30:06 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		cub_key(int key, t_data *cub)
{
	if (key == ' ')
		cub->start = 1;
	if (key == 'w' || key == 'W')
		player_move_forward(cub);
	else if (key == 's' || key == 'S')
		player_move_backward(cub);
	else if (key == 'd' || key == 'D')
		player_move_right(cub);
	else if (key == 'a' || key == 'A')
		player_move_left(cub);
	else if (key == 'e' || key == 'E')
		player_rotate_right(cub);
	else if (key == 'q' || key == 'Q')
		player_rotate_left(cub);
	else if (key == 0xFF1B)
		cub_exit(cub, NULL, 1);
	return (0);
}
