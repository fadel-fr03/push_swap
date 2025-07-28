/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:14:49 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:44:37 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
