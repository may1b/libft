/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:59:53 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 19:12:30 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	if (!node)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	node->next = ft_lstmap(lst->next, f, del);
	return (node);
}
