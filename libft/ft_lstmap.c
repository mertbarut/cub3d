/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:18:12 by mbarut            #+#    #+#             */
/*   Updated: 2021/05/22 18:58:51 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*element;

	if (!lst || !f)
		return (NULL);
	element = ft_lstnew((*f)(lst->content));
	if (!element)
		return (NULL);
	list = element;
	while (lst->next)
	{
		lst = lst->next;
		element = ft_lstnew((*f)(lst->content));
		if (!element)
			ft_lstclear(&list, del);
		ft_lstadd_back(&list, element);
	}
	return (list);
}
