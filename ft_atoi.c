/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:26:12 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 20:23:29 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	size_t	i;
	int		sign;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

#ifdef TESTING

typedef struct s_test {
	const char	*input;
}	t_test;

static bool	run_test(t_test t)
{
	return (ft_atoi(t.input) == atoi(t.input));
}

int	main(void)
{
	static t_test	tests[] = {
	{"0"}, {"123"}, {"-456"}, {"+789"},
	{"  42"}, {"  -42"}, {"  +42"}, {"42abc"},
	{""}, {"2147483647"}, {"-2147483648"}};
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
	ft_print_summary("ft_atoi", passed, count);
	return (passed != count);
}

#endif
