#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

void	del_node_content(void *content)
{
	free(content);
}

void	print_node_content(void *content)
{
	printf("%s -> ", (char *)content);
}

int	main(void)
{
	printf("=======================================\n");
	printf("        LIBFT INTEGRATION TEST         \n");
	printf("=======================================\n\n");

	// 1. Part 1: Libc Functions Tests
	printf("--- Part 1: Libc Tests ---\n");
	printf("ft_strlen('42Amman'): %zu\n", ft_strlen("42Amman"));
	printf("ft_atoi('   -42'): %d\n", ft_atoi("   -42"));
	printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
	printf("ft_isdigit('9'): %d\n", ft_isdigit('9'));
	
	char str_bzero[10] = "123456789";
	ft_bzero(str_bzero, 4);
	printf("ft_bzero check (index 4): %c\n", str_bzero[4]);

	// 2. Part 2: Additional Functions Tests
	printf("\n--- Part 2: Additional Functions Tests ---\n");
	char *dup = ft_strdup("Libft Project");
	printf("ft_strdup: %s\n", dup);
	free(dup);

	char *joined = ft_strjoin("Hello ", "World!");
	printf("ft_strjoin: %s\n", joined ? joined : "NULL");
	free(joined);

	char *itoa_val = ft_itoa(INT_MIN);
	printf("ft_itoa (INT_MIN): %s\n", itoa_val ? itoa_val : "NULL");
	free(itoa_val);

	printf("ft_putstr_fd / ft_putnbr_fd test output: ");
	ft_putstr_fd("Val = ", 1);
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);

	// 3. Part 3: Linked List Tests
	printf("\n--- Part 3: Linked List Tests ---\n");
	t_list *head = ft_lstnew(ft_strdup("Node 1"));
	t_list *node2 = ft_lstnew(ft_strdup("Node 2"));
	t_list *node3 = ft_lstnew(ft_strdup("Node 3"));

	ft_lstadd_back(&head, node2);
	ft_lstadd_front(&head, node3); // Structure: Node 3 -> Node 1 -> Node 2

	printf("List Elements: ");
	ft_lstiter(head, print_node_content);
	printf("NULL\n");

	printf("List Size: %d\n", ft_lstsize(head));
	printf("Last Node Content: %s\n", (char *)ft_lstlast(head)->content);

	ft_lstclear(&head, del_node_content);
	printf("List cleared successfully: %s\n", head == NULL ? "OK" : "FAIL");

	printf("\n=======================================\n");
	printf("         ALL TESTS COMPLETED           \n");
	printf("=======================================\n");

	return (0);
}