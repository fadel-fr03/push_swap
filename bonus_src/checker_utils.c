/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:45:18 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:45:18 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_inc/checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(0);
}

void	read_operation(t_stack **a, t_stack **b, char *operation)
{
	if (!ft_strcmp(operation, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(operation, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(operation, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(operation, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(operation, "pb\n"))
		pb (b, a, true);
	else if (!ft_strcmp(operation, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(operation, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(operation, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(operation, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(operation, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(operation, "rrr\n"))
		rrr(a, b, true);
	else
		print_error(a, b);
}

void	get_operation(t_stack **a, t_stack **b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		read_operation(a, b, operation);
		free(operation);
		operation = get_next_line(0);
	}
	free(operation);
}

void	write_checker_res(t_stack *a, t_stack *b)
{
	if (check_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
