/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:15:09 by magrass           #+#    #+#             */
/*   Updated: 2026/04/20 20:21:21 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	to_alloc;	

	if (!nmemb || !size)
		return (malloc(0));
	to_alloc = nmemb * size;
	ptr = malloc(to_alloc);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, to_alloc);
	return (ptr);
}
