/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:30:06 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 14:35:36 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*joined_str;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	joined_str = malloc(s1_size + s2_size + 1);
	if (!joined_str)
		return (NULL);
	ft_memcpy(joined_str, s1, s1_size);
	ft_memcpy(joined_str + s1_size, s2, s2_size + 1);
	return (joined_str);
}
