/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:00:55 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/02 15:50:17 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cub_pressx(t_data *cub)
{
	cub_exit(cub, NULL, 1);
	return (0);
}

int	cub_key(int key, t_data *cub)
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
	else if (key == KEY_RIGHT_ARROW)
		player_rotate_right(cub);
	else if (key == KEY_LEFT_ARROW)
		player_rotate_left(cub);
	else if (key == KEY_ESCAPE)
		cub_exit(cub, NULL, 1);
	return (0);
}
