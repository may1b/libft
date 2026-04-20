/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:38:13 by magrass           #+#    #+#             */
/*   Updated: 2026/04/20 21:42:10 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_size;
	size_t	i;
	char	*new_str;

	str_size = ft_strlen(s);
	new_str = malloc(str_size + 1);
	i = 0;
	while (i < str_size)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}
