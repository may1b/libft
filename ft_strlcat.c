/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:22:41 by magrass           #+#    #+#             */
/*   Updated: 2026/04/18 13:44:13 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (i < size - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

#ifdef TESTING

typedef struct s_test {
	char	dst_init[32];
	char	src[32];
	size_t	size;
}	t_test;

static bool	run_test(t_test t)
{
	char	fd[64];
	char	ld[64];
	size_t	fr;
	size_t	lr;

	memset(fd, 0xCC, 64);
	memset(ld, 0xCC, 64);
	strcpy(fd, t.dst_init);
	strcpy(ld, t.dst_init);
	fr = ft_strlcat(fd, t.src, t.size);
	lr = strlcat(ld, t.src, t.size);
	return (fr == lr && memcmp(fd, ld, 64) == 0);
}

int	main(void)
{
	static t_test	tests[] = {
	{{"Hello"}, {" World"}, 20}, {{"Hello"}, {" World"}, 8},
	{{"Hello"}, {" World"}, 0}, {{"Hello"}, {" World"}, 5},
	{{""}, {"Hello"}, 10}};
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
	ft_print_summary("ft_strlcat", passed, count);
	return (passed != count);
}

#endif
