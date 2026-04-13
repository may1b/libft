/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:21:09 by magrass           #+#    #+#             */
/*   Updated: 2026/04/13 21:52:26 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// size_t
// __strlcpy (char *__restrict dest, const char *__restrict src, size_t size)
// {
//   size_t src_length = strlen (src);
//   if (__glibc_unlikely (src_length >= size))
//     {
//       if (size > 0)
// 	{
// 	  /* Copy the leading portion of the string.  The last
// 	     character is subsequently overwritten with the NUL
// 	     terminator, but the destination size is usually a
// 	     multiple of a small power of two, so writing it twice
// 	     should be more efficient than copying an odd number of
// 	     bytes.  */
// 	  memcpy (dest, src, size);
// 	  dest[size - 1] = '\0';
// 	}
//     }
//   else
//     /* Copy the string and its terminating NUL character.  */
//     memcpy (dest, src, src_length + 1);
//   return src_length;
// }
/**
 * @param dest - The destination buffer
 * @param src  - The string to copy (has to be NUL-terminated)
 * @param size - sizeof(dest) ([n] characters to copy + NUL-terminator)
 * @return strlen(src) (size of src string)
*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i] != '\0')
		i++;
	if (size)
		dest[size - 1] = '\0';
	return (i);
}
// typedef struct {
// 	char src[20];
// 	size_t size;
// 	char	dest[40];
// } Test;
// typedef struct {
// 	char s[20];
// } S;
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// int	main(void)
// {
// 	Test tests[5] = {0};
// 	Test testsCopy[5] = {0};
// 	*((S*)&tests[0].src) = (S){"World!"};
// 	tests[0].size = 10;
// 	*((S*)&tests[1].src) = (S){"Hello, World!"};
// 	tests[1].size = 10;
// 	*((S*)&tests[2].src) = (S){"Hello, World!"};
// 	tests[2].size = 5;
// 	*((S*)&tests[3].src) = (S){"Hello, World!"};
// 	tests[2].size = 1;
// 	*((S*)&tests[4].src) = (S){"Hello, World!"};
// 	tests[2].size = 0;

// 	memcpy(testsCopy, tests, sizeof(testsCopy));
// 	for (size_t i = 0; i < 5; ++i) {
// 		Test* ft_currentTest = &tests[i];
// 		Test* currentTest = &testsCopy[i];
// 		ft_strlcpy(ft_currentTest->dest,
//           ft_currentTest->src, ft_currentTest->size);
// 		glibc_strlcpy(currentTest->dest, currentTest->src, currentTest->size);
// 		write(1, "Test ", 5);
// 		char num = i + '1';
// 		write(1, &num, 1);
// 		write(1, " out of 5\n", 10);
// 		if (memcmp(currentTest->dest, ft_currentTest->dest, 40) != 0) {
// 			write(1, "Expected:\n", 10);
// 			write(1, currentTest->dest, 40);
// 			write(1, "\n", 1);
// 			write(1, "But got:\n", 9);
// 			write(1, ft_currentTest->dest, 40);
// 			write(1, "\n", 1);
// 		} else {
// 			write(1, "Perfect 11/10\n", 14);
// 		}
// 	}
// }
