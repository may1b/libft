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
#include <stdint.h>
#ifdef TESTING
# include "libft.h"
#endif

int	ft_memcmp(const void *s1, const void *s2, size_t n);

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
// TODO: factor out the whole testing stuff to the header

# define GREEN	"\x1b[32m"
# define RED	"\x1b[31m"
# define RESET	"\x1b[0m"	

typedef struct s_test {
	char	*area1;
	char	*area2;
	size_t	n;
}	t_test;

bool	run_test(t_test test)
{
	int	result;
	int	libc_result;

	result = ft_memcmp(test.area1, test.area2, test.n);
	libc_result = memcmp(test.area1, test.area2, test.n);
	return (result == libc_result);
}

void	print_tests(size_t n, bool results[static n], t_test tests[static n])
{
	size_t	i;

	printf("TEST %s\n", "`ft_memcmp`");
	i = 0;
	while (i < n)
	{
		printf("%zu/%zu: [`%s`, `%s`, %zu] -> ", i + 1, n + 1, tests[i].area1,
			tests[i].area2, tests[i].n);
		if (results[i])
			printf(GREEN"[PASSED]\n"RESET);
		else
			printf(GREEN"[FAILED]\n"RESET);
		i++;
	}
}

int	main(void)
{
	static t_test	tests[] = {{"", "", 0}, {"a", "a", 1},
	{"abc", "abc", 3}, {"a", "b", 1}};
	bool			results[(sizeof(tests) / sizeof(t_test))];
	size_t			i;

	i = 0;
	while (i < (sizeof(tests) / sizeof(t_test)))
	{
		results[i] = run_test(tests[i]);
		i++;
	}
	print_tests(sizeof(tests) / sizeof(t_test), results, tests);
}

#endif
