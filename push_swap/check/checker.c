#include "../includes/push_swap.h"

static void	swap_top_nodes_both_stacks(t_stack *a, t_stack *b)
{
	swap_top_nodes(a, "");
	swap_top_nodes(b, "");
}

static void	shift_both_stacks(t_stack *a, t_stack *b, char *direction)
{
	if (direction[0] == 'u')
	{
		shift_up_stack(a, "");
		shift_up_stack(b, "");
	}
	if (direction[0] == 'd')
	{
		shift_down_stack(a, "");
		shift_down_stack(b, "");
	}
}

static void	execute_push_swap(t_stack *a, t_stack *b, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 3))
		swap_top_nodes(a, "");
	else if (ft_strncmp(instruction, "sb\n", 3))
		swap_top_nodes(b, "");
	else if (ft_strncmp(instruction, "ss\n", 3))
		swap_top_nodes_both_stacks(a, b);
	else if (ft_strncmp(instruction, "pb\n", 3))
		push_node_to_other_stack(a, b, "");
	else if (ft_strncmp(instruction, "pa\n", 3))
		push_node_to_other_stack(b, a, "");
	else if (ft_strncmp(instruction, "ra\n", 3))
		shift_up_stack(a, "");
	else if (ft_strncmp(instruction, "rb\n", 3))
		shift_up_stack(b, "");
	else if (ft_strncmp(instruction, "rr\n", 3))
		shift_both_stacks(a, b, "up");
	else if (ft_strncmp(instruction, "rra\n", 4))
		shift_down_stack(a, "");
	else if (ft_strncmp(instruction, "rrb\n", 4))
		shift_down_stack(b, "");
	else if (ft_strncmp(instruction, "rrr\n", 4))
		shift_both_stacks(a, b, "down");
	else
		error_message_and_exit(a, b);
}

static int	read_instruction(char *instruction, t_stack *a, t_stack *b)
{
	int		i;
	int		bytes_read;

	i = 0;
	while (i < 4)
	{
		bytes_read = read(0, instruction + i, 1);
		if (bytes_read < 0)
			error_message_and_exit(a, b);
		if (bytes_read == 0 && i == 0)
			return (0);
		if (instruction[i] == '\n')
			break ;
		i += 1;
	}
	return (1);
}

void	ft_push_swap(t_stack *a, t_stack *b)
{
	char	instruction[4];

	if (a->first)
	{
		while (read_instruction(&instruction[0], a, b))
			execute_push_swap(a, b, instruction);
		if (stack_is_sorted(a) && b->size == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
