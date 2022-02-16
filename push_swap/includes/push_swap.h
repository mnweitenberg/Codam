#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list	t_list;
typedef struct s_stack	t_stack;

struct s_list {
	t_list	*next;
	t_list	*prev;
	int		value;
};

struct s_stack {
	t_list	*first;
	t_list	*last;
	size_t	size;
};

//	COMMON
int		error_message_and_exit(t_stack *a, t_stack *b);
void	swap_top_nodes(t_stack *stack, char *instruction);
void	push_node_to_other_stack(t_stack *src, t_stack *dst, char *instruction);
void	shift_up_stack(t_stack *stack, char *instruction);
void	shift_down_stack(t_stack *stack, char *instruction);

void	append_node_to_front_of_stack(t_stack *list, t_list *node);
void	append_node_to_back_of_stack(t_stack *list, t_list *node);
t_list	*copy_and_delete_first_list(t_stack *list);
t_list	*copy_and_delete_last_list(t_stack *list);
void	free_nodes_in_list(t_list *node);

int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		stack_is_sorted(t_stack *list);

//	SORTER
void	ft_push_swap(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack *a, t_stack *b);
void	move_b_to_a(t_stack *a, t_stack *b);
void	sort_list_of_three(t_stack *a);
void	sort_medium_list(t_stack *a, t_stack *b);	
void	execute_rotations(t_stack *a, t_stack *b,
			int rotations_a, int rotations_b);

#endif
