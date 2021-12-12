/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:59:27 by mbarut            #+#    #+#             */
/*   Updated: 2021/05/19 15:56:22 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int			org_size;
	static char	*dup;
	char		*dup_offset;

	org_size = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * org_size + 1);
	if (dup == NULL)
		return ((char *) NULL);
	dup_offset = dup;
	while (*s)
	{
		*dup_offset = *s;
		dup_offset++;
		s++;
	}
	*dup_offset = '\0';
	return (dup);
}
