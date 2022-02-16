#include "../includes/push_swap.h"
#include <stdlib.h>

static t_list	*copy_linked_list(t_stack *a, t_stack *b)
{
	t_list	*new_head;
	t_list	*list;
	t_list	*p;

	list = a->first;
	new_head = malloc(sizeof(t_list));
	if (!new_head)
		error_message_and_exit(a, b);
	new_head->value = list->value;
	p = new_head;
	list = list->next;
	while (list != NULL)
	{
		p->next = malloc(sizeof(t_list));
		if (!p->next)
			error_message_and_exit(a, b);
		p = p->next;
		p->value = list->value;
		list = list->next;
	}
	p->next = NULL;
	return (new_head);
}

static void	sort_linked_list(t_list **h)
{
	int		a;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *h;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp2->value < temp1->value)
			{
				a = temp1->value;
				temp1->value = temp2->value;
				temp2->value = a;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

static int	get_median(t_stack *a, t_stack *b)
{
	t_list	*lst;
	int		i;
	int		n;
	int		median;

	lst = copy_linked_list(a, b);
	sort_linked_list(&lst);
	n = a->size / 2;
	i = 0;
	while (i < n)
	{
		lst = lst->next;
		i++;
	}
	median = lst->value;
	free_nodes_in_list(lst);
	return (median);
}

void	move_a_to_b(t_stack *a, t_stack *b)
{
	int		median;

	while (a->size > 1)
	{
		median = get_median(a, b);
		if (a->first->value < median)
			push_node_to_other_stack(a, b, "pb\n");
		else
			shift_up_stack(a, "ra\n");
	}
}
