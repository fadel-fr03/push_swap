#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

/*		Checker Functions		*/
int		check_arg(char *str);
int		check_repetition(t_stack *s, int n);

/*		Freeing Dynamic Structures		*/
void	free_two_dimensional_array(char **array);
void	free_stack(t_stack **s);
void	found_error(t_stack **s, char **str, bool arg_2);

/*		Split Function		*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

/*		Function to Initialize Stack a		*/
void	create_stack(t_stack **a, char **str, bool arg_2);

/*		Stack Utility Functions		*/
int		stack_len(t_stack *s);
void	add_to_stack(t_stack **s, int n);
int		check_sorted(t_stack *s);
t_stack	*return_minimum(t_stack *s);
t_stack	*return_maximum(t_stack *s);

/*		Stack Operations		*/
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);

/*		Turk Sort Utils		*/
void	set_current_position(t_stack *s);
void	update_cheapest(t_stack *b);
void	init_nodes_a(t_stack *a, t_stack *b);;
void	init_nodes_b(t_stack *a, t_stack *b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	move_a_to_b(t_stack **a, t_stack **b);
t_stack	*return_cheapest(t_stack *s);
void	finish_rotation(t_stack **s, t_stack *top_node, char stack_name);

/*		Sorting		*/
void	sort_three(t_stack **a);
void	sort(t_stack **a, t_stack **b);
void	turk_sort(t_stack **a, t_stack **b);
#endif