*This project has been created as part of the 42 curriculum by magrass.*

# libft — Your Very First Own Library

## Description

**libft** is a custom C library built from scratch as part of the 42 school curriculum. The goal is to reimplement a selection of standard C library functions (libc), along with additional utility functions that will be reused throughout future 42 projects.

The library covers three main areas:
- **Part 1 – Libc functions:** Re-implementations of standard functions such as `ft_strlen`, `ft_memcpy`, `ft_atoi`, etc.
- **Part 2 – Additional functions:** Custom utility functions not found in libc or present in a different form, such as `ft_split`, `ft_itoa`, `ft_substr`, and output helpers like `ft_putstr_fd`.
- **Part 3 – Linked list functions:** A set of functions to create and manipulate singly-linked lists using the `t_list` structure.

---

## Function Reference

### Part 1 – Libc Functions

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if a character is alphabetic |
| `ft_isdigit` | Checks if a character is a digit |
| `ft_isalnum` | Checks if a character is alphanumeric |
| `ft_isascii` | Checks if a character is in the ASCII table |
| `ft_isprint` | Checks if a character is printable |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills a memory area with a constant byte |
| `ft_bzero` | Sets a memory area to zero |
| `ft_memcpy` | Copies a memory area |
| `ft_memmove` | Copies a memory area, handling overlap |
| `ft_strlcpy` | Copies a string with size limit |
| `ft_strlcat` | Concatenates strings with size limit |
| `ft_toupper` | Converts a character to uppercase |
| `ft_tolower` | Converts a character to lowercase |
| `ft_strchr` | Locates first occurrence of a character in a string |
| `ft_strrchr` | Locates last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_memchr` | Searches for a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Locates a substring in a string, up to n characters |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates zero-initialised memory |
| `ft_strdup` | Duplicates a string using malloc |

### Part 2 – Additional Functions

| Function | Description |
|---|---|
| `ft_substr` | Returns a substring from a string |
| `ft_strjoin` | Concatenates two strings into a new one |
| `ft_strtrim` | Trims characters from both ends of a string |
| `ft_split` | Splits a string by a delimiter into an array |
| `ft_itoa` | Converts an integer to a string |
| `ft_strmapi` | Applies a function to each character, returns new string |
| `ft_striteri` | Applies a function to each character in-place |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd` | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor |

### Part 3 – Linked List Functions

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of a list |
| `ft_lstsize` | Returns the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the end of a list |
| `ft_lstdelone` | Frees a single node's content and the node itself |
| `ft_lstclear` | Frees all nodes in a list |
| `ft_lstiter` | Iterates over a list and applies a function to each node |
| `ft_lstmap` | Creates a new list by applying a function to each node |

---

## Instructions

### Compilation

Clone the repository and run `make` at its root:

```bash
make
make clean # optionally cleans up the object (.o) files
```

This will compile all source files and produce `libft.a` at the root of the repository.

### Available Makefile rules

| Rule | Action |
|---|---|
| `make` / `make all` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Rebuilds everything from scratch |

### Usage

To use libft in another project, include the header and link the archive:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft
```

---

## Resources

- [Linux man pages](https://man7.org/linux/man-pages/)
- [FreeBSD man pages](https://man.freebsd.org/cgi/man.cgi)

### AI Usage

AI was used for assistance (asking questions) and verification of some of the functions which I was unsure about.
Otherwise all I wrote all of the code myself.
