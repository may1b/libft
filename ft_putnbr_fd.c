/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:40:27 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 20:12:45 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_buf(int n, char *buf)
{
	int	len;
	int	tmp;

	len = (n < 0);
	if (!len)
		n = -n;
	tmp = n;
	if (tmp == 0)
		tmp = -1;
	while (tmp != 0 && ++len)
		tmp /= 10;
	buf[len] = '\0';
	if (n == 0)
		return (buf[0] = '0', buf);
	if (len != (n < 0))
		buf[0] = '-';
	while (n != 0)
	{
		buf[--len] = '0' - (n % 10);
		n /= 10;
	}
	return (buf);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[1000];
	size_t	strnum_size;

	ft_itoa_buf(n, buf);
	strnum_size = ft_strlen(buf);
	write(fd, buf, strnum_size);
}
