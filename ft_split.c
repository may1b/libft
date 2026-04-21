/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:40:41 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 22:11:32 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Code which i once wrote:
Not sure why i used uint16_t instead of size_t
ArrayListSV splitSVByChar(SV sv, char splitBy)
{
    ArrayListSV svList = $initArrayList(SV);
    uint16_t prevSplit = 0;
    for (uint16_t i = 0; i < sv.len; ++i) {
        if (sv.items[i] == splitBy) {
            SV slicedSv = svSlice(sv, prevSplit, i - prevSplit);
            $append((&svList), slicedSv);
            prevSplit = i + 1;
        }
    }
    if (prevSplit < sv.len) {
        SV slicedSv = svSlice(sv, prevSplit, sv.len - prevSplit);
        $append((&svList), slicedSv);
    }
    return svList;
}
*/

static size_t	count_toks(char *s, char *cs, size_t cs_len)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_strncmp(&s[i], cs, cs_len) == 0)
			i += cs_len;
		if (s[i])
		{
			n++;
			while (s[i] && ft_strncmp(&s[i], cs, cs_len) != 0)
				i++;
		}
	}
	return (n);
}

static char	*next_token(char *s, char *cs, size_t cs_len, size_t *pos)
{
	size_t	start;

	while (s[*pos] && ft_strncmp(&s[*pos], cs, cs_len) == 0)
		*pos += cs_len;
	if (!s[*pos])
		return (NULL);
	start = *pos;
	while (s[*pos] && ft_strncmp(&s[*pos], cs, cs_len) != 0)
		(*pos)++;
	return (ft_substr(s, start, *pos - start));
}

static char	**ft_split_by(char *str, char *charset)
{
	size_t	cs_len;
	char	**result;
	size_t	i;
	size_t	tok_i;

	cs_len = ft_strlen(charset);
	result = malloc((count_toks(str, charset, cs_len) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	tok_i = 0;
	result[tok_i] = next_token(str, charset, cs_len, &i);
	while (result[tok_i])
	{
		tok_i++;
		result[tok_i] = next_token(str, charset, cs_len, &i);
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	delim[2];

	delim[0] = c;
	delim[1] = '\0';
	return (ft_split_by((char *)s, delim));
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
