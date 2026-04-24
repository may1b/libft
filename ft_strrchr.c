/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:44:18 by magrass           #+#    #+#             */
/*   Updated: 2026/04/24 19:16:55 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	size_t	strlen_;

	strlen_ = 0;
	while (s[strlen_])
		strlen_++;
	if ((unsigned char)c == '\0')
		return ((char *)&s[strlen_]);
	while (strlen_)
	{
		strlen_--;
		if ((unsigned char)((s[strlen_])) == (unsigned char)c)
			return ((char *)&s[strlen_]);
	}
	return (NULL);
}

#ifdef TESTING

typedef struct s_test {
	char	*s;
	int		c;
}	t_test;

static bool	run_test(t_test t)
{
	return (ft_strrchr(t.s, t.c) == strrchr(t.s, t.c));
}

int	main(void)
{
	static t_test	tests[] = {
	{"hello", 'l'}, {"hello", 'o'}, {"hello", 'z'},
	{"hello", '\0'}, {"abcabc", 'b'}, {"ababa", 'a'}};
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
	ft_print_summary("ft_strrchr", passed, count);
	return (passed != count);
}

#endif
