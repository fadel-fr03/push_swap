#include "../inc/push_swap.h"

int	stack_len(t_stack *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

void	add_to_stack(t_stack **s, int n)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->cheapest = false;
	new_node->target = NULL;
	new_node->above_median = false;
	new_node->price = INT_MAX;
	new_node->index = INT_MIN;
	if (*s == NULL)
		*s = new_node;
	else
	{
		temp = *s;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

int	check_sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	return (1);
}

t_stack	*return_minimum(t_stack *s)
{
	long	min;
	t_stack	*temp;

	if (!s)
		return (NULL);
	min = LONG_MAX;
	while (s)
	{
		if (s->data < min)
		{
			min = s->data;
			temp = s;
		}
		s = s->next;
	}
	return (temp);
}

t_stack	*return_maximum(t_stack *s)
{
	long	max;
	t_stack	*temp;

	if (!s)
		return (NULL);
	max = LONG_MIN;
	while (s)
	{
		if (s->data > max)
		{
			max = s->data;
			temp = s;
		}
		s = s->next;
	}
	return (temp);
}
