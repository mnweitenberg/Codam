#include "../includes/push_swap.h"

void	sort_list_of_three(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	while (!stack_is_sorted(a))
	{
		top = a->first->value;
		middle = a->first->next->value;
		bottom = a->first->next->next->value;
		if (top < middle && top < bottom)
			shift_down_stack(a, "rra\n");
		else if (top > middle && top < bottom)
			swap_top_nodes(a, "sa\n");
		else
			shift_up_stack(a, "ra\n");
	}
}

static int	find_min_value(t_list *lst)
{
	int	min_value;

	min_value = lst->value;
	while (lst)
	{
		if (lst->value < min_value)
			min_value = lst->value;
		lst = lst->next;
	}
	return (min_value);
}

static int	find_position_of_min_value(t_list *lst)
{
	int	min_value;
	int	i;

	i = 0;
	min_value = find_min_value(lst);
	while (lst)
	{
		if (lst->value == min_value)
			return (i);
		lst = lst->next;
		i++;
	}
	return (i);
}

static void	rotate_stack(t_stack *a)
{
	unsigned int	position_of_min_value;

	position_of_min_value = find_position_of_min_value(a->first);
	if (position_of_min_value > (a->size / 2))
		shift_down_stack(a, "rra\n");
	else
		shift_up_stack(a, "ra\n");
}

void	sort_medium_list(t_stack *a, t_stack *b)
{
	while (!stack_is_sorted(a))
	{
		while (a->size > 3)
		{
			if (a->first->value == find_min_value(a->first))
				push_node_to_other_stack(a, b, "pb\n");
			else
				rotate_stack(a);
		}
		sort_list_of_three(a);
	}
	while (b->size > 0)
		push_node_to_other_stack(b, a, "pa\n");
}
