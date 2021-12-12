/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:14:19 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/27 15:18:31 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countsubstr(char const *s, char c)
{
	int	i;
	int	count;

	if (s == 0 || s[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_malloc(char const *s, char c)
{
	int		len;
	char	**array;

	len = ft_countsubstr(s, c);
	array = malloc(sizeof(*array) * (len + 1));
	if (array == 0)
		return (0);
	return (array);
}

static int	ft_next_word_count(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **array, int i)
{
	int	j;

	j = 0;
	while (j < i && array[j] != 0)
	{
		free(array[j]);
		j++;
	}
	free(array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	int		i;
	int		j;
	char	**array;

	if (s == 0)
		return (0);
	k = 0;
	i = -1;
	array = ft_malloc(s, c);
	while (++i < ft_countsubstr(s, c))
	{
		j = 0;
		array[i] = malloc(ft_next_word_count(s, c, k) + 1);
		if (!array[i])
			return (ft_free(array, i));
		while (s[k] != '\0' && s[k] == c)
			k++;
		while (s[k] != '\0' && s[k] != c)
			array[i][j++] = s[k++];
		array[i][j] = '\0';
	}
	array[i] = 0;
	return (array);
}
