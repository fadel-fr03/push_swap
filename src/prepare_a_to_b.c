/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:44:20 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:44:21 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_current_position(t_stack *s)
{
	int	i;
	int	median;

	i = 0;
	if (!s)
		return ;
	median = stack_len(s) / 2;
	while (s)
	{
		s->index = i;
		if (i <= median)
			s->above_median = true;
		else
			s->above_median = false;
		s = s->next;
		++i;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack		*current_b;
	t_stack		*target;
	long		best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->data < a->data
				&& current_b->data > best_match_index)
			{
				best_match_index = current_b->data;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = return_maximum(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	update_push_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->price = a->index;
		if (!(a->above_median))
			a->price = len_a - (a->index);
		if (a->target->above_median)
			a->price += a->target->index;
		else
			a->price += len_b - (a->target->index);
		a = a->next;
	}
}

void	update_cheapest(t_stack *stack)
{
	long		cheapest_value;
	t_stack		*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->price < cheapest_value)
		{
			cheapest_value = stack->price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_a(a, b);
	update_push_price(a, b);
	update_cheapest(a);
}
