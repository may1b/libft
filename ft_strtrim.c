/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:36:52 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 14:36:52 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	char_is_one_of(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	start = 0;
	while (s1[start] && char_is_one_of(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_is_one_of(s1[end - 1], set))
		end--;
	new_str = malloc(end - start + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1 + start, end - start);
	new_str[end - start] = '\0';
	return (new_str);
}

#ifdef TESTING

typedef struct s_test {
	const char	*s1;
	const char	*set;
	const char	*expected;
}	t_test;

static bool	run_test(t_test t)
{
	char	*result;
	bool	ok;

	result = ft_strtrim(t.s1, t.set);
	if (!result)
		return (false);
	ok = (strcmp(result, t.expected) == 0);
	free(result);
	return (ok);
}

int	main(void)
{
	static t_test	tests[] = {
	{"  hello  ", " ", "hello"},
	{"xxhelloxx", "x", "hello"},
	{"hello", "xyz", "hello"},
	{"aaaa", "a", ""},
	{"", " ", ""},
	{"  \thello\t  ", " \t", "hello"},
	{"hello", "", "hello"}};
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
	ft_print_summary("ft_strtrim", passed, count);
	return (passed != count);
}

#endif
