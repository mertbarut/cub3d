/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:58:24 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 14:21:07 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	lastnode = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (lastnode->next != NULL)
			lastnode = lastnode->next;
		lastnode->next = new;
	}
}
