/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:22:41 by magrass           #+#    #+#             */
/*   Updated: 2026/04/13 21:53:20 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_len;
	unsigned int	dst_len;

	j = 0;
	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dst_len;
	if (size == 0)
		return (src_len);
	if (size < dst_len)
		return (src_len + size);
	else
	{
		while (src[j] && (dst_len + j) < size)
			dest[i++] = src[j++];
		if ((dst_len + j) == size && dst_len < size)
			dest[--i] = '\0';
		else
			dest[i] = '\0';
		return (src_len + dst_len);
	}
}
