/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:40:41 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 20:23:29 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#define DA_INIT_CAP	10 

static void	str_da_append(t_str_da *da, char *str);
static long	find_in_str(char *haystack, char *needle);
static char	*strn_alloc_and_cpy(char *str, size_t until);
/*
// Code which i once wrote:
// Not sure why i used uint16_t instead of size_t
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
    // Add the last segment after the final delimiter
    if (prevSplit < sv.len) {
        SV slicedSv = svSlice(sv, prevSplit, sv.len - prevSplit);
        $append((&svList), slicedSv);
    }
    return svList;
}
*/

char	**ft_split(char *str, char *charset)
{
	size_t		i;
	size_t		pos;
	t_str_da	da;
	char		*new_str;

	da = (t_str_da){malloc(DA_INIT_CAP * sizeof(char **)), 0, DA_INIT_CAP};
	i = 0;
	while (find_in_str(&str[i], charset) != -1)
	{
		pos = find_in_str(&str[i], charset);
		if (pos > 0)
		{
			new_str = strn_alloc_and_cpy(&str[i], pos);
			if (!new_str)
				return (NULL);
			str_da_append(&da, new_str);
			pos += ft_strlen(charset);
		}
		i += pos;
	}
	str_da_append(&da, NULL);
	return (da.items);
}

static char	*strn_alloc_and_cpy(char *str, size_t until)
{
	size_t	i;
	char	*new_str;

	new_str = malloc(until + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < until)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[until] = '\0';
	return (new_str);
}

static long	find_in_str(char *haystack, char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] && needle[j] == haystack[i + j])
			j++;
		if (j == ft_strlen(needle))
			return (i);
		i++;
	}
	return (-1);
}

static void	str_da_append(t_str_da *da, char *str)
{
	char	**new_ptr;
	size_t	i;

	if (da->cap <= da->size + 1)
	{
		da->cap *= 2;
		new_ptr = malloc(sizeof(char **) * da->cap);
		if (!new_ptr)
			return ;
		i = 0;
		while (i < da->size)
		{
			new_ptr[i] = da->items[i];
			i++;
		}
		free(da->items);
		da->items = new_ptr;
	}
	da->items[da->size++] = str;
}
