#include "../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(a, false);
	else if (first > second && second > third)
	{
		sa(a, false);
		rra(a, false);
	}
	else if (first > second && second < third && first > third)
		ra(a, false);
	else if (first < second && second > third && first < third)
	{
		sa(a, false);
		ra(a, false);
	}
	else if (first < second && second > third && first > third)
		rra(a, false);
}
