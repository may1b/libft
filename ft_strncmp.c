/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:21:50 by magrass           #+#    #+#             */
/*   Updated: 2026/04/14 15:25:42 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	n--;
	i = 0;
	while (n-- && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#ifdef TESTING

typedef struct s_test {
	char	*s1;
	char	*s2;
	size_t	n;
}	t_test;

static bool	run_test(t_test t)
{
	int	fr;
	int	lr;

	fr = ft_strncmp(t.s1, t.s2, t.n);
	lr = strncmp(t.s1, t.s2, t.n);
	return ((fr < 0 && lr < 0) || (fr > 0 && lr > 0)
		|| (fr == 0 && lr == 0));
}

int	main(void)
{
	static t_test	tests[] = {
	{"abc", "abc", 3}, {"abc", "abd", 3}, {"abc", "abc", 0},
	{"abc", "abd", 2}, {"", "", 1}, {"abc", "ab", 3}};
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
	ft_print_summary("ft_strncmp", passed, count);
	return (passed != count);
}

#endif
