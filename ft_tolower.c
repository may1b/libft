/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:05:36 by magrass           #+#    #+#             */
/*   Updated: 2026/04/14 14:15:10 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c);

static char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] -= 'A' - 'a';
		i++;
	}
	return (str);
}

int	ft_tolower(int c)
{
	return (*ft_strlowcase((char *)&c));
}
