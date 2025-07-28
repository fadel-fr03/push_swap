#include "../inc/push_swap.h"

t_stack	*return_cheapest(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s)
	{
		if (s->cheapest)
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	finish_rotation(t_stack **s, t_stack *top_node, char stack_name)
{
	while (*s != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(s, false);
			else
				rra(s, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(s, false);
			else
				rrb(s, false);
		}
	}
}
