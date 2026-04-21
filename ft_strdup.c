/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:22:35 by magrass           #+#    #+#             */
/*   Updated: 2026/04/20 20:27:11 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_size;
	char	*new_str;

	str_size = ft_strlen(s);
	new_str = malloc(str_size + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, str_size + 1);
	return (new_str);
}

#ifdef TESTING

static bool	run_test(const char *s)
{
	char	*result;
	bool	ok;

	result = ft_strdup(s);
	if (!result)
		return (false);
	ok = (strcmp(result, s) == 0 && result != s);
	free(result);
	return (ok);
}

int	main(void)
{
	static const char	*tests[] = {"hello", "", "abc def", "a"};
	size_t				count;
	size_t				passed;
	size_t				i;
	bool				ok;

	count = sizeof(tests) / sizeof(char *);
	passed = 0;
	i = 0;
	while (i < count)
	{
		ok = run_test(tests[i]);
		ft_print_line(i, count, ok);
		passed += ok;
		i++;
	}
	ft_print_summary("ft_strdup", passed, count);
	return (passed != count);
}

#endif
