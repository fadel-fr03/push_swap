/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:14:32 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:46:07 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack **a, t_stack **b, bool checker)
{
	t_stack	*temp;

	if (b == NULL || *b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->prev = NULL;
	if (*a == NULL)
	{
		*a = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *a;
		(*a)->prev = temp;
		*a = temp;
	}
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool checker)
{
	t_stack	*temp;

	if (a == NULL || *a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->prev = NULL;
	if (*b == NULL)
	{
		*b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *b;
		(*b)->prev = temp;
		*b = temp;
	}
	if (!checker)
		write(1, "pb\n", 3);
}
