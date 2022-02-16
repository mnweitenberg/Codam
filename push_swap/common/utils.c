#include "../includes/push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}

int	stack_is_sorted(t_stack *list)
{
	t_list	*node;

	node = list->first;
	while (node != NULL && node->next != NULL)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (1);
}
