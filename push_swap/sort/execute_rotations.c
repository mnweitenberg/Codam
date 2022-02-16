#include "../includes/push_swap.h"

static void	rotate_both(t_stack *a, t_stack *b, int rotations_together)
{
	while (rotations_together > 0)
	{
		shift_up_stack(a, "r");
		shift_up_stack(b, "r\n");
		rotations_together--;
	}
	while (rotations_together < 0)
	{
		shift_down_stack(a, "rr");
		shift_down_stack(b, "r\n");
		rotations_together++;
	}
}

static void	rotate_a(t_stack *a, int rotations_a)
{
	while (rotations_a > 0)
	{
		shift_up_stack(a, "ra\n");
		rotations_a--;
	}
	while (rotations_a < 0)
	{
		shift_down_stack(a, "rra\n");
		rotations_a++;
	}
}

static void	rotate_b(t_stack *b, int rotations_b)
{
	while (rotations_b > 0)
	{
		shift_up_stack(b, "rb\n");
		rotations_b--;
	}
	while (rotations_b < 0)
	{
		shift_down_stack(b, "rrb\n");
		rotations_b++;
	}
}

/*
if rotations_a or rotations_b are positive, this means that the stack
should be shifted upwards (ra, rb or rr), if these numbers are negative
it should be shifted downwards (rra, rrb, rrr)
*/
void	execute_rotations(t_stack *a, t_stack *b,
	int rotations_a, int rotations_b)
{
	int	rotations_together;

	rotations_together = 0;
	if (rotations_a < 0 && rotations_b < 0)
		rotations_together = ft_max(rotations_a, rotations_b);
	if (rotations_a > 0 && rotations_b > 0)
		rotations_together = ft_min(rotations_a, rotations_b);
	rotate_both(a, b, rotations_together);
	rotate_a(a, rotations_a - rotations_together);
	rotate_b(b, rotations_b - rotations_together);
}
