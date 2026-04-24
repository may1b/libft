/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:38:13 by magrass           #+#    #+#             */
/*   Updated: 2026/04/24 19:18:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_size;
	size_t	i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	str_size = ft_strlen(s);
	new_str = ft_calloc(str_size + 1, 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < str_size)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}

#ifdef TESTING

static char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

typedef struct s_test {
	const char	*input;
	const char	*expected;
}	t_test;

static bool	run_test(t_test t)
{
	char	*result;
	bool	ok;

	result = ft_strmapi(t.input, to_upper);
	if (!result)
		return (false);
	ok = (strcmp(result, t.expected) == 0);
	free(result);
	return (ok);
}

int	main(void)
{
	static t_test	tests[] = {
	{"hello", "HELLO"}, {"", ""}, {"Hello World", "HELLO WORLD"},
	{"abc123", "ABC123"}};
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
	ft_print_summary("ft_strmapi", passed, count);
	return (passed != count);
}

#endif
