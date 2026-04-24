/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:26:29 by magrass           #+#    #+#             */
/*   Updated: 2026/04/24 19:05:33 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (!dest && !src)
		return (dest);
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = ((const char *)src)[n];
		}
	}
	return (dest);
}

#ifdef TESTING

typedef struct s_test {
	char	init[32];
	size_t	dst_off;
	size_t	src_off;
	size_t	n;
}	t_test;

static bool	run_test(t_test t)
{
	char	fb[32];
	char	lb[32];

	memcpy(fb, t.init, 32);
	memcpy(lb, t.init, 32);
	ft_memmove(fb + t.dst_off, fb + t.src_off, t.n);
	memmove(lb + t.dst_off, lb + t.src_off, t.n);
	return (memcmp(fb, lb, 32) == 0);
}

int	main(void)
{
	static t_test	tests[] = {
	{{"abcdef"}, 2, 0, 4}, {{"abcdef"}, 0, 2, 4},
	{{"hello world"}, 0, 0, 11}, {{"test"}, 0, 0, 0},
	{{"overlap"}, 3, 1, 4}, {{"overlap"}, 1, 3, 4}};
	size_t			count;
	size_t			passed;
	size_t			i;
	bool			ok;

	count = sizeof(tests) / sizeof(t_test);
	passed = 0;
	i = 0;
	while (i < count)
	{
		ok = run_test(tests[i]);
		ft_print_line(i, count, ok);
		passed += ok;
		i++;
	}
	ft_print_summary("ft_memmove", passed, count);
	return (passed != count);
}

#endif
