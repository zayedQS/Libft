*This project has been created as part of the 42 curriculum by zhasan.*

# Libft - @42 Amman

> Your very first own C library.

## 📝 Description

**Libft** is the first project in the 42 Network Core Curriculum. The goal is to build your own C library: a collection of general-purpose functions that you will reuse in all your future 42 projects.

The library is split into three parts:

1. **Libc functions** - re-implementations of standard C functions, with the same prototypes and behaviors as the originals (only the `ft_` prefix is added).
2. **Additional functions** - utility functions that are either not in the `libc` or exist in a different form (strings, conversions, file descriptor output).
3. **Linked list functions** - a small toolkit to manipulate singly linked lists using the `t_list` structure.

Building this library from the ground up provides a deep understanding of low-level C programming, memory allocation (`malloc`, `free`), pointer arithmetic, and data structures.

The result is a static library, `libft.a`, created with the `ar` command at the root of the repository.

---

## 🛠️ Library Details

### Part 1 - Libc Functions

Same prototypes and behaviors as the originals (see their `man` pages), without relying on any external function except `malloc` where needed.

| Category | Functions | Notes |
|----------|-----------|-------|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Return `1` if the character matches the class, `0` otherwise |
| Character conversion | `ft_toupper`, `ft_tolower` | Convert a letter to upper/lower case |
| String functions | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi` | Work directly on C strings |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` | Work on raw bytes |
| Allocation (uses `malloc`) | `ft_calloc`, `ft_strdup` | If `nmemb` or `size` is `0`, `ft_calloc` returns a unique pointer that can be passed to `free()` |

### Part 2 - Additional Functions

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Returns a new substring of `s` starting at index `start`, with a maximum length of `len` |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Returns a new string made of `s1` followed by `s2` |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Returns a copy of `s1` with the characters from `set` removed from the beginning and the end |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits `s` using `c` as a delimiter; returns a `NULL`-terminated array of newly allocated strings |
| `ft_itoa` | `char *ft_itoa(int n)` | Converts an integer (negatives included) to a newly allocated string |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies `f` to each character (with its index) and returns a new string with the results |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Applies `f` to each character (with its index, by address) so it can be modified in place |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Writes a character to the given file descriptor |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Writes a string to the given file descriptor |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Writes a string followed by a newline to the given file descriptor |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Writes an integer to the given file descriptor |

### Part 3 - Linked List Functions

The following structure is declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

* `content` - the data stored in the node (`void *` allows any type of data).
* `next` - the address of the next node, or `NULL` if it is the last one.

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Creates a new node with the given content and `next` set to `NULL` |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Adds the node `new` at the beginning of the list |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst)` | Counts the number of nodes in the list |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node of the list |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Adds the node `new` at the end of the list |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees a node's content with `del`, then frees the node (not the next one) |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees the given node and all its successors, then sets the list pointer to `NULL` |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies `f` to the content of each node |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Builds a new list by applying `f` to each node's content; uses `del` to clean up if an allocation fails |

---

## ⚙️ Instructions

### 1. Compile the Library

Clone this repository and run:

```bash
make
```

This builds the `libft.a` static library at the root of the repository, using `cc` with the flags `-Wall -Wextra -Werror`.

Makefile rules:

* `make` or `make all` - Compiles all the source files and creates `libft.a`.
* `make clean` - Removes the object files (`.o`).
* `make fclean` - Removes the object files and `libft.a`.
* `make re` - Recompiles the entire library from scratch.

### 2. Use It in Your Code

Include the header in your source file:

```c
#include "libft.h"
```

Then compile your code and link it with `libft.a`:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

### 3. Example

```c
#include "libft.h"

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello 42 amman", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

---

## 📚 Resources

* `man` pages for each re-implemented function (e.g. `man 3 strlen`, `man 3 memmove`)
* *The C Programming Language* - Kernighan & Ritchie
* [Norminette](https://github.com/42School/norminette) - the 42 coding standard
* Peer discussions with other 42 students

**AI usage:** AI was used as a learning aىd to better understand certain concepts
  (such as pointers, memory allocation with `malloc`/`free`, and how some libc functions behave).
---

## 👤 Author

* **Zayed Hasan**
* 42 Amman Student
