/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:44:18 by magrass           #+#    #+#             */
/*   Updated: 2026/04/14 15:16:45 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*strrchr(const char *s, int c);

char	*strrchr(const char *s, int c)
{
	size_t	strlen_;

	strlen_ = 0;
	while (s[strlen_])
		strlen_++;
	if (c == '\0')
		return ((char *)&s[strlen_]);
	while (strlen_ && s[strlen_] != c)
		strlen_--;
	return ((char *)&s[strlen_]);
}

#if 0

// # include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (printf("YOU SHALL PROVIDE 2 ARGUMENTS!\n"), 1);
	printf("YOU PROVIDED: `%s`\n", argv[1]);
	printf("IN WHICH THE LAST OCCURENCE THY SHALL BE: '%c'\n", argv[2][0]);
	printf("IS THY FOUDING CORRECT?\n THE ANSWER:\n`%s`\n",
		strrchr(argv[1], argv[2][0]));
}

#endif
