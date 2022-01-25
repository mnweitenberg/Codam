#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*new_node;

	new_node = (void *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
