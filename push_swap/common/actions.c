#include "../includes/push_swap.h"

static void	ft_putstr(char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		write(1, &c, 1);
		str++;
	}
}

void	push_node_to_other_stack(t_stack *src, t_stack *dst, char *instruction)
{
	t_list	*temp_node;

	if (src->size < 1)
		return ;
	src->size -= 1;
	dst->size += 1;
	temp_node = copy_and_delete_first_list(src);
	append_node_to_front_of_stack(dst, temp_node);
	ft_putstr(instruction);
	return ;
}

void	shift_up_stack(t_stack *stack, char *instruction)
{
	t_list	*temp_node;

	temp_node = copy_and_delete_first_list(stack);
	append_node_to_back_of_stack(stack, temp_node);
	ft_putstr(instruction);
	return ;
}

void	shift_down_stack(t_stack *stack, char *instruction)
{
	t_list	*temp_node;

	temp_node = copy_and_delete_last_list(stack);
	append_node_to_front_of_stack(stack, temp_node);
	ft_putstr(instruction);
	return ;
}

void	swap_top_nodes(t_stack *stack, char *instruction)
{
	int	temp_value;

	if (!stack || !stack->first || !stack->first->next)
		return ;
	temp_value = stack->first->value;
	stack->first->value = stack->first->next->value;
	stack->first->next->value = temp_value;
	ft_putstr(instruction);
	return ;
}
