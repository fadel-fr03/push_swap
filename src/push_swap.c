#include "../inc/push_swap.h"

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
	if (check_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (!a)
		found_error(&a, str, argc == 2);
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
