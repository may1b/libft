/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:36:52 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 14:36:52 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	char_is_one_of(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	start = 0;
	while (s1[start] && char_is_one_of(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_is_one_of(s1[end - 1], set))
		end--;
	new_str = malloc(end - start + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1 + start, end - start);
	new_str[end - start] = '\0';
	return (new_str);
}
