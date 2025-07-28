/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:14:09 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:44:11 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	check_arg(char *str)
{
	int	i;

	if (!str || (!ft_isdigit(str[0]) && !ft_issign(str[0])))
		return (0);
	if (ft_issign(str[0]) && !ft_isdigit(str[1]))
		return (0);
	if (ft_issign(str[0]))
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_repetition(t_stack *s, int n)
{
	if (!s)
		return (0);
	while (s)
	{
		if (s->data == n)
			return (1);
		s = s->next;
	}
	return (0);
}
