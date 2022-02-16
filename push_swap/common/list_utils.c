#include "../includes/push_swap.h"

void	append_node_to_front_of_stack(t_stack *stack, t_list *node)
{
	if (node == NULL)
		return ;
	node->next = stack->first;
	node->prev = NULL;
	if (stack->first != NULL)
		stack->first->prev = node;
	else
		stack->last = node;
	stack->first = node;
}

void	append_node_to_back_of_stack(t_stack *stack, t_list *node)
{
	if (node == NULL)
		return ;
	node->prev = stack->last;
	node->next = NULL;
	if (stack->last != NULL)
		stack->last->next = node;
	else
		stack->first = node;
	stack->last = node;
}

t_list	*copy_and_delete_first_list(t_stack *stack)
{
	t_list	*node;

	node = stack->first;
	if (node == NULL)
		return (NULL);
	stack->first = node->next;
	if (node->next != NULL)
		node->next->prev = NULL;
	else
		stack->last = NULL;
	return (node);
}

t_list	*copy_and_delete_last_list(t_stack *stack)
{
	t_list	*node;

	node = stack->last;
	if (node == NULL)
		return (NULL);
	stack->last = node->prev;
	if (node->prev != NULL)
		node->prev->next = NULL;
	else
		stack->first = NULL;
	return (node);
}

void	free_nodes_in_list(t_list *node)
{
	t_list	*temp;

	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp);
		temp = NULL;
	}
}
