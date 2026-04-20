/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:29:58 by magrass           #+#    #+#             */
/*   Updated: 2026/04/20 20:36:39 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	new_strlen;
	char	*substr;

	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	new_strlen = ft_strlen(&s[start]);
	
}