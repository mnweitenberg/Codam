#include "../includes/push_swap.h"

/*
if (a1 < b1 && b1 < a2)
	for example
	1	2
	3
	just needs ra, pa for perfect placing

if we get to the next if statement, it means that b1 is either bigger or
smaller than all the values in stack_a.

if (a2 < a1 && a1 < b1)
	for example
	4	5
	1
	2
	3
	just needs ra, pa for perfect placing, b1 will be the max value 

if (b1 < a2 && a2 < a1)
	for example
	6	1
	2
	3
	4
	5
	just needs ra, pa for perfect placing, b1 will be the min value
*/
static int	calculate_rotations_in_a(t_stack *a, int b1)
{
	int		moves_to_pa;
	t_list	*stack_a;
	int		a1;
	int		a2;

	moves_to_pa = 1;
	stack_a = a->first;
	while (stack_a->next != NULL)
	{
		a1 = stack_a->value;
		a2 = stack_a->next->value;
		if (a1 < b1 && b1 < a2)
			break ;
		if (a2 < a1 && a1 < b1)
			break ;
		if (b1 < a2 && a2 < a1)
			break ;
		moves_to_pa++;
		stack_a = stack_a->next;
	}
	return (moves_to_pa);
}

/*
if ((reverse ra + rb) < (total combined rotations))
	than it's faster to reverse rotate stack_a
if (ra + reverse rb < (total combined rotations))
	than it's faster to (also) reverse rotate stack_b
*/
static void	check_if_reverse_rotations_are_optimal(t_stack *a, t_stack *b,
	int *ra_to_pa, int *rb_to_pa)
{
	int		rra_to_pa;
	int		rrb_to_pa;

	rra_to_pa = a->size - *ra_to_pa;
	rrb_to_pa = b->size - *rb_to_pa;
	if ((rra_to_pa + *rb_to_pa) < (*ra_to_pa + *rb_to_pa))
		*ra_to_pa = -rra_to_pa;
	if ((ft_abs(*ra_to_pa) + rrb_to_pa) < (*ra_to_pa + *rb_to_pa))
		*rb_to_pa = -rrb_to_pa;
}

/*
for every value in stack_b check:
- 	ra_to_pa: 
	how many rotations of stack_a do you need until you can	push 
	the current value to it's correct place in stack_a.
-	rb_to_pa: 
	the position of the current value in stack_b.
-	rotations_a and rotations_b: 
	when the amount of moves (ra_to_pa and rb_to_pa combined)
	needed for a correct placing is	the lowest amount we have
	encountered so far, we store the values.
	the amount of rotations_a and/or rotations_b can be negative, 
	this means we need reverse rotations
*/
static void	calculate_rotations(t_stack *a, t_stack *b,
	int *rotations_a, int *rotations_b)
{
	int		i;
	t_list	*stack_b;
	int		ra_to_pa;
	int		rb_to_pa;

	i = 0;
	stack_b = b->first;
	while (stack_b != NULL)
	{
		ra_to_pa = calculate_rotations_in_a(a, stack_b->value);
		rb_to_pa = i;
		check_if_reverse_rotations_are_optimal(a, b, &ra_to_pa, &rb_to_pa);
		if ((ft_abs(ra_to_pa) + ft_abs(rb_to_pa))
			< (ft_abs(*rotations_a) + ft_abs(*rotations_b)))
		{
			*rotations_a = ra_to_pa;
			*rotations_b = rb_to_pa;
		}
		i += 1;
		stack_b = stack_b->next;
	}
}

void	move_b_to_a(t_stack *a, t_stack *b)
{
	int		rotations_a;
	int		rotations_b;

	rotations_a = a->size;
	rotations_b = b->size;
	calculate_rotations(a, b, &rotations_a, &rotations_b);
	execute_rotations(a, b, rotations_a, rotations_b);
	push_node_to_other_stack(b, a, "pa\n");
}
