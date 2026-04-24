/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:29:58 by magrass           #+#    #+#             */
/*   Updated: 2026/04/24 19:21:02 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	new_strlen;
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	new_strlen = ft_strlen(&s[start]);
	if (len < new_strlen)
		new_strlen = len;
	substr = ft_calloc(new_strlen + 1, 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, &s[start], new_strlen);
	return (substr);
}

#ifdef TESTING

typedef struct s_test {
	const char		*s;
	unsigned int	start;
	size_t			len;
	const char		*expected;
}	t_test;

static bool	run_test(t_test t)
{
	char	*result;
	bool	ok;

	result = ft_substr(t.s, t.start, t.len);
	if (!result)
		return (false);
	ok = (strcmp(result, t.expected) == 0);
	free(result);
	return (ok);
}

int	main(void)
{
	static t_test	tests[] = {
	{"Hello World", 6, 5, "World"},
	{"Hello", 10, 5, ""},
	{"Hello", 0, 0, ""},
	{"Hello", 1, 100, "ello"},
	{"", 0, 5, ""},
	{"Hello", 0, 5, "Hello"}};
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
	ft_print_summary("ft_substr", passed, count);
	return (passed != count);
}

#endif
