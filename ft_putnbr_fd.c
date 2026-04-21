/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:40:27 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 16:49:27 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_buf(int n, char *str)
{
	int		len;
	int		neg;

	neg = (n < 0);
	if (!neg)
		n = -n;
	str[len] = '\0';
	if (neg)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[1000];
	size_t	strnum_size;

	ft_itoa_buf(n, buf);
	strnum_size = ft_strlen(buf);
	write(fd, buf, strnum_size);
}
