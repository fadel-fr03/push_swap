/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:14:54 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:46:47 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack **a, bool checker)
{
	int	len;

	len = stack_len(*a);
	if (a == NULL || *a == NULL || len <= 1)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool checker)
{
	int	len;

	len = stack_len(*b);
	if (b == NULL || *b == NULL || len <= 1)
		return ;
	*b = (*b)->next;
	(*b)->prev->prev = *b;
	(*b)->prev->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = (*b)->prev;
	(*b)->next = (*b)->prev;
	(*b)->prev = NULL;
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	sa(a, true);
	sb(b, true);
	if (!checker)
		write(1, "ss\n", 3);
}
