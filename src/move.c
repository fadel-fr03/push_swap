#include "../inc/push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rev_rotate_both(a, b, cheapest_node);
	finish_rotation(a, cheapest_node, 'a');
	finish_rotation(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	finish_rotation(a, (*b)->target, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->data != return_minimum(*a)->data)
	{
		if (return_minimum(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
