/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:56:24 by magrass           #+#    #+#             */
/*   Updated: 2026/04/21 18:26:28 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# ifdef TESTING
#  include <stdio.h>
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

// Used in ft_split implementation
typedef struct s_str_da {
	char	**items;
	size_t	size;
	size_t	cap;
}	t_str_da;

char	**ft_split(char *str, char *charset);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);

int		ft_lstsize(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *new);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

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
