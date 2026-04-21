/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:29:58 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 14:28:52 by magrass          ###   ########.fr       */
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
	if (len < new_strlen)
		new_strlen = len;
	substr = ft_calloc(new_strlen + 1, 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, &s[start], new_strlen);
	return (substr);
}
