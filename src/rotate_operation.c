#include "../inc/push_swap.h"

void	ra(t_stack **a, bool checker)
{
	t_stack	*temp;
	int		len;

	len = stack_len(*a);
	if (a == NULL || *a == NULL || len <= 1)
		return ;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool checker)
{
	t_stack	*temp;
	int		len;

	len = stack_len(*b);
	if (b == NULL || *b == NULL || len <= 1)
		return ;
	temp = *b;
	while (temp->next)
		temp = temp->next;
	temp->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	ra(a, true);
	rb(b, true);
	if (!checker)
		write(1, "rr\n", 3);
}
