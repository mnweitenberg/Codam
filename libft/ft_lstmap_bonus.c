#include "libft.h"

t_list	*create_head_node(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
	{
		ft_lstclear(&lst, del);
		return (0);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;

	if (!lst || !f)
		return (0);
	new_node = create_head_node(lst, f, del);
	if (new_node == 0)
		return (0);
	new_list = new_node;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_list, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, new_node);
	}
	return (new_list);
}
