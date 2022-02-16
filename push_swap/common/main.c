#include "../includes/push_swap.h"

int	error_message_and_exit(t_stack *a, t_stack *b)
{
	free_nodes_in_list(a->first);
	free_nodes_in_list(b->first);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

static void	convert_argv_to_int(const char *str, t_list *new_node,
	t_stack *a, t_stack *b)
{
	int		polarity;
	long	value;

	polarity = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		polarity *= -1;
		str++;
	}
	if (!*str)
		error_message_and_exit(a, b);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			error_message_and_exit(a, b);
		value = value * 10 + (*str - '0') * polarity;
		str++;
	}
	if (value < INT_MIN || value > INT_MAX)
		error_message_and_exit(a, b);
	new_node->value = (int)value;
}

static void	check_if_value_is_duplicate(t_list *list, t_list *new_node,
	t_stack *a, t_stack *b)
{
	while (list)
	{
		if (list->value == new_node->value)
			error_message_and_exit(a, b);
		list = list->next;
	}
}

static void	initialize_stack(int argc, char **argv, t_stack *a, t_stack *b)
{
	t_list	*new_node;
	int		i;

	a->size = argc - 1;
	a->first = NULL;
	a->last = NULL;
	b->size = 0;
	b->first = NULL;
	b->last = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = (void *)malloc(sizeof(t_list));
		if (!new_node)
			error_message_and_exit(a, b);
		convert_argv_to_int(argv[i], new_node, a, b);
		check_if_value_is_duplicate(a->first, new_node, a, b);
		append_node_to_back_of_stack(a, new_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	initialize_stack(argc, argv, &a, &b);
	ft_push_swap(&a, &b);
	free_nodes_in_list(a.first);
	free_nodes_in_list(b.first);
	return (EXIT_SUCCESS);
}
