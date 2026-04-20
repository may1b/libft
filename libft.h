/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:56:24 by magrass           #+#    #+#             */
/*   Updated: 2026/04/18 13:44:24 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stddef.h>
# ifdef TESTING
#  include <stdio.h>
#  include <stdbool.h>
#  include <string.h>
#  define FT_GREEN "\x1b[32m"
#  define FT_RED "\x1b[31m"
#  define FT_RESET "\x1b[0m"
# endif

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

int		ft_isalnum(int c);

# ifdef TESTING

static void	ft_print_line(size_t idx, size_t total, bool ok)
{
	if (ok)
		printf(FT_GREEN "%zu/%zu: PASS" FT_RESET "\n", idx + 1, total);
	else
		printf(FT_RED "%zu/%zu: FAIL" FT_RESET "\n", idx + 1, total);
}

static void	ft_print_summary(const char *name, size_t p, size_t t)
{
	printf("\n%s: ", name);
	if (p == t)
		printf(FT_GREEN "%zu/%zu passed" FT_RESET "\n\n", p, t);
	else
		printf(FT_RED "%zu/%zu passed" FT_RESET "\n\n", p, t);
}
# endif

#endif
