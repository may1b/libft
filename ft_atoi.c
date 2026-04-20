/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:26:12 by magrass           #+#    #+#             */
/*   Updated: 2026/04/20 17:40:16 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	long	i;
	bool	negative;

	i = 0;
	result = 0;
	negative = false;
	while (nptr[i] != '\0')
	{
		if (nptr[i] <= '9' && nptr[i] >= '0')
		{
			result += nptr[i] - '0';
			result *= 10;
		}
		else if (nptr[i] == '-' && !i)
			negative = true;
		i++;
	}
	if (negative)
		result = -result;
	return (result / 10);
}
