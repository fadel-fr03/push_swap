#include "../inc/push_swap.h"

void	turk_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !check_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_current_position(*a);
	min_on_top(a);
}

void	sort(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		turk_sort(a, b);
}
