/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:17:41 by magrass           #+#    #+#             */
/*   Updated: 2026/04/14 14:42:50 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

#ifdef TESTING

typedef struct s_test {
	char	*s;
	int		c;
}	t_test;

static bool	run_test(t_test t)
{
	return (ft_strchr(t.s, t.c) == strchr(t.s, t.c));
}

int	main(void)
{
	static t_test	tests[] = {
	{"hello", 'l'}, {"hello", 'h'}, {"hello", 'z'},
	{"hello", '\0'}, {"", '\0'}, {"abcabc", 'b'}};
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
	ft_print_summary("ft_strchr", passed, count);
	return (passed != count);
}

#endif
