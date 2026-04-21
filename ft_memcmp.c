/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:41:54 by magrass           #+#    #+#             */
/*   Updated: 2026/04/18 13:31:54 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const uint8_t	*area1;
	const uint8_t	*area2;

	area1 = s1;
	area2 = s2;
	i = 0;
	while (i < n && area1[i] == area2[i])
		i++;
	if (i == n)
		return (0);
	return (area1[i] - area2[i]);
}

#ifdef TESTING

typedef struct s_test {
	char	*area1;
	char	*area2;
	size_t	n;
}	t_test;

static bool	run_test(t_test t)
{
	int	fr;
	int	lr;

	fr = ft_memcmp(t.area1, t.area2, t.n);
	lr = memcmp(t.area1, t.area2, t.n);
	return ((fr < 0 && lr < 0) || (fr > 0 && lr > 0)
		|| (fr == 0 && lr == 0));
}

int	main(void)
{
	static t_test	tests[] = {{"", "", 0}, {"a", "a", 1},
	{"abc", "abc", 3}, {"a", "b", 1}};
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
	ft_print_summary("ft_memcmp", passed, count);
	return (passed != count);
}

#endif
