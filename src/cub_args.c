/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:40:11 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/02 16:14:08 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_args(int argc, char **argv)
{
	char	*extension;

	if (argc != 2)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	extension = ft_strrchr(argv[1], '.');
	if (ft_strcmp(extension, ".cub") != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
