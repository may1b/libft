/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:22:35 by magrass           #+#    #+#             */
/*   Updated: 2026/04/20 20:27:11 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_size;
	char	*new_str;

	str_size = ft_strlen(s);
	new_str = malloc(str_size + 1);
	ft_memcpy(new_str, s, str_size + 1);
	return (new_str);
}
