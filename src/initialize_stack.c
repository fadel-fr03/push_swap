#include "../inc/push_swap.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static long	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

void	create_stack(t_stack **a, char **str, bool arg_2)
{
	long	n;
	int		i;

	i = 0;
	while (str[i])
	{
		if (!check_arg(str[i]))
			found_error(a, str, arg_2);
		n = ft_atoi(str[i]);
		if (n > INT_MAX || n < INT_MIN)
			found_error(a, str, arg_2);
		if (check_repetition(*a, (int)n))
			found_error(a, str, arg_2);
		add_to_stack(a, (int)n);
		i++;
	}
	if (arg_2)
		free_two_dimensional_array(str);
}
