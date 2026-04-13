/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:26:29 by magrass           #+#    #+#             */
/*   Updated: 2026/04/13 21:50:26 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t		i;

	if (!dest || !src || src == dest)
		return (dest);
	destination = (char *)dest;
	source = (const char *)src;
	if (destination < source)
	{
		i = 0;
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
			((destination[n - 1] = source[n - 1]) || 1) && n--;
	}
	return (dest);
}
