/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:54:48 by magrass           #+#    #+#             */
/*   Updated: 2026/04/13 21:04:14 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: vv move to ft.h vv
/**
 * @description: This function checks if a character is printable
 * The space character is the smallest printable character (32)
 * `~` is the largest printable character (for ASCII)
 * So if a character is between 32 and 126 it is printable
*/
int	ft_isprint(int c);

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
