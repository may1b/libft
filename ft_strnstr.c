/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:09:43 by magrass           #+#    #+#             */
/*   Updated: 2026/04/20 17:24:16 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (i + needle_len <= len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && j < needle_len)
			j++;
		if (j == needle_len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

#ifdef TESTING

typedef struct s_test {
	char	*haystack;
	char	*needle;
	size_t	len;
}	t_test;

static bool	run_test(t_test t)
{
	return (ft_strnstr(t.haystack, t.needle, t.len)
		== strnstr(t.haystack, t.needle, t.len));
}

int	main(void)
{
	static t_test	tests[] = {
	{"hello world", "world", 11}, {"hello world", "world", 5},
	{"hello world", "", 11}, {"hello world", "hello", 11},
	{"aaab", "aab", 4}, {"abc", "abc", 3}, {"abc", "abcd", 3},
	{"abc", "xyz", 3}, {"hello", "hello world", 5},
	{"hello world", "world", 0}};
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
	ft_print_summary("ft_strnstr", passed, count);
	return (passed != count);
}

#endif
