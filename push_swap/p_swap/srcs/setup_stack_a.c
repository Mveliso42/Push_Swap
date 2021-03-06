/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:52:47 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/22 18:52:52 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int				end_of_num(char *str)
{
	return (*str == ' ' || !(*(str + 1))) ? 1 : 0;
}

int				get_nums(char *str, t_stack *stack_a)
{
	int			sign;
	long int	num;

	num = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		else if (ft_isdigit(*str))
			num = (num * 10) + (*str - '0');

		if (end_of_num(str))
		{
			num *= sign;
			if (!is_valid(num, stack_a) && ft_printf("Error\n"))
				exit(1);
			stack_a->nums[stack_a->cur_size] = num;
			stack_a->cur_size++;
			num = 0;
			sign = 1;
		}

		str++;
	}
	return (1);
}

int				make_stack_a(char **av, int ac, t_stack *stack_a)
{
	int			i;

	i = 0;
	while (i < ac)
	{
		get_nums(av[i], stack_a);
		i++;
	}
	return (1);
}
