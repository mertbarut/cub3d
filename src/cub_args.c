/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:40:11 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/04 11:25:23 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_args(int argc, char **argv)
{
	char	*extension;

	if (argc != 2)
	{
		printf("Error\n");
		printf("Game accepts 1 input, no more, no less, thank you :)\n");
		exit(EXIT_FAILURE);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		printf("Error\n");
		printf("Wrong input format\n");
		exit(EXIT_FAILURE);
	}
	extension = ft_strrchr(argv[1], '.');
	if (ft_strcmp(extension, ".cub") != 0)
	{
		printf("Error\n");
		printf("Wrong input format\n");
		exit(EXIT_FAILURE);
	}
}
