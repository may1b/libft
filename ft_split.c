/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:40:41 by magrass           #+#    #+#             */
/*   Updated: 2026/04/24 19:14:56 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_toks(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static char	*next_token(char const *s, char c, size_t *pos)
{
	size_t	start;

	while (s[*pos] && s[*pos] == c)
		(*pos)++;
	if (!s[*pos])
		return (NULL);
	start = *pos;
	while (s[*pos] && s[*pos] != c)
		(*pos)++;
	return (ft_substr(s, start, *pos - start));
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	tok_i;

	if (!s)
		return (NULL);
	result = malloc((count_toks(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	tok_i = 0;
	result[tok_i] = next_token(s, c, &i);
	while (result[tok_i])
	{
		tok_i++;
		result[tok_i] = next_token(s, c, &i);
	}
	return (result);
}

#ifdef TESTING

int	main(void)
{
	char	**r;
	size_t	p;
	bool	ok;

	p = 0;
	r = ft_split("hello world", ' ');
	ok = (r != NULL);
	ok = (ok && !strcmp(r[0], "hello") && !strcmp(r[1], "world") && !r[2]);
	ft_print_line(0, 3, ok);
	p += ok;
	r = ft_split(",a,", ',');
	ok = (r != NULL);
	ok = (ok && !strcmp(r[0], "a") && !r[1]);
	ft_print_line(1, 3, ok);
	p += ok;
	r = ft_split("", ',');
	ok = ((r != NULL) && !r[0]);
	ft_print_line(2, 3, ok);
	p += ok;
	ft_print_summary("ft_split", p, 3);
	return (p != 3);
}

#endif
