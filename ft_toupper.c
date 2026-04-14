/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:06:40 by magrass           #+#    #+#             */
/*   Updated: 2026/04/14 14:13:54 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c);

static char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
		i++;
	}
	return (str);
}

int	ft_toupper(int c)
{
	return (*ft_strupcase((char *)&c));
}
