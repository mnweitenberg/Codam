#include "../includes/push_swap.h"

static int	count_moves_to_smallest_value(t_stack *a)
{
	t_list	*node;
	int		i;

	i = 0;
	node = a->first;
	while (node != NULL)
	{
		i += 1;
		if (node->next == NULL || node->next->value < node->value)
			break ;
		node = node->next;
	}
	return (i);
}

static void	rotate_smallest_value_to_top(t_stack *a)
{
	int	no_of_moves_from_top;
	int	no_of_moves_from_bottom;

	no_of_moves_from_top = count_moves_to_smallest_value(a);
	no_of_moves_from_bottom = a->size - no_of_moves_from_top;
	if (no_of_moves_from_top < no_of_moves_from_bottom)
	{
		while (no_of_moves_from_top--)
			shift_up_stack(a, "ra\n");
	}
	else
	{
		while (no_of_moves_from_bottom--)
			shift_down_stack(a, "rra\n");
	}
}

void	ft_push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort_list_of_three(a);
	else if (a->size >= 4 && a->size <= 15)
		sort_medium_list(a, b);
	else
	{	
		while (a->size > 2)
			move_a_to_b(a, b);
		while (b->size > 0)
			move_b_to_a(a, b);
		rotate_smallest_value_to_top(a);
	}
}
