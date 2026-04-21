/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:06:00 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 15:06:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		neg;

	neg = (n < 0);
	if (!neg)
		n = -n;
	len = num_len(n) + neg;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (neg)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}

#ifdef TESTING

typedef struct s_test {
	int			n;
	const char	*expected;
}	t_test;

static bool	run_test(t_test t)
{
	char	*result;
	bool	ok;

	result = ft_itoa(t.n);
	if (!result)
		return (false);
	ok = (strcmp(result, t.expected) == 0);
	free(result);
	return (ok);
}

int	main(void)
{
	static t_test	tests[] = {
	{0, "0"}, {1, "1"}, {-1, "-1"},
	{123, "123"}, {-456, "-456"},
	{2147483647, "2147483647"}, {-2147483648, "-2147483648"}};
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
	ft_print_summary("ft_itoa", passed, count);
	return (passed != count);
}

#endif
