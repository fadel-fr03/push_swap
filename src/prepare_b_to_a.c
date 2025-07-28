#include "../inc/push_swap.h"

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack		*current_a;
	t_stack		*target;
	long		best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data
				&& current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = return_minimum(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_b(a, b);
}
