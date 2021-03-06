/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:50:58 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/22 18:51:00 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		is_duplicate(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->cur_size)
	{
		if (stack->nums[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int		is_valid(int num, t_stack *stack_a)
{
	if ((num > 2147483647) ||
			(num < -2147483648) ||
			is_duplicate(stack_a, num))
		return (0);
	else
		return (1);
}

int		is_sorted(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (nums[i] > nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		is_revsorted(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (nums[i] < nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		are_numbers(char *str)
{
	int	nums;

	nums = 0;
	while (*str)
	{
		if (*str == '-' && ft_isdigit(*(str + 1)))
			str++;
		else if (*str == ' ' && (ft_isdigit(*(str - 1)) ||
							ft_isdigit(*(str + 1))))
		{
			str++;
			nums++;
		}
		else if (ft_isdigit(*str))
		{
			str++;
			if (!*str)
				nums++;
		}
		else
			return (0);
	}
	return (nums);
}
