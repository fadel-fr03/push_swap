/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:14:44 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:46:22 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack **a, bool checker)
{
	t_stack	*temp;
	int		len;

	len = stack_len(*a);
	if (a == NULL || *a == NULL || len <= 1)
		return ;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->next = *a;
	temp->prev = NULL;
	*a = temp;
	temp->next->prev = temp;
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool checker)
{
	t_stack	*temp;
	int		len;

	len = stack_len(*b);
	if (b == NULL || *b == NULL || len <= 1)
		return ;
	temp = *b;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->next = *b;
	temp->prev = NULL;
	*b = temp;
	temp->next->prev = temp;
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	rra(a, true);
	rrb(b, true);
	if (!checker)
		write(1, "rrr\n", 4);
}
