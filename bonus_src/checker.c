/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:45:21 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:45:21 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_inc/checker.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = argv + 1;
	create_stack(&a, str, argc == 2);
	get_operation(&a, &b);
	write_checker_res(a, b);
	free_stack(&a);
	free_stack(&b);
}
