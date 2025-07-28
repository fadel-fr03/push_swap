/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:14:11 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:44:10 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_two_dimensional_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	free_stack(t_stack **s)
{
	t_stack	*temp;

	if (!s || !*s)
		return ;
	while (*s)
	{
		temp = (*s)->next;
		free(*s);
		*s = temp;
	}
	*s = NULL;
}

void	found_error(t_stack **s, char **str, bool arg_2)
{
	free_stack(s);
	if (arg_2)
		free_two_dimensional_array(str);
	write(2, "Error\n", 6);
	exit(0);
}
