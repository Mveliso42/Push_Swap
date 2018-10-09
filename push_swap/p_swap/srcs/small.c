/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:53:05 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/22 18:53:06 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char		*handle_three_a(char *solution, t_super_stack *super_stack)
{
	solution = update_solution(solution, "rra");
	perform_op("rra", super_stack->stack_a,
				super_stack->stack_b, super_stack->flags);
	solution = update_solution(solution, "sa");
	perform_op("sa", super_stack->stack_a,
				super_stack->stack_b, super_stack->flags);
	return (solution);
}

char		*handle_three_b(char *solution, t_super_stack *super_stack)
{
	if (super_stack->stack_a->nums[0] > super_stack->stack_a->nums[2])
	{
		solution = update_solution(solution, "ra");
		perform_op("ra", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
	}
	else
	{
		solution = update_solution(solution, "sa");
		perform_op("sa", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
	}
	return (solution);
}

char		*handle_three_c(char *solution, t_super_stack *super_stack)
{
	if (is_revsorted(super_stack->stack_a->nums,
						super_stack->stack_a->cur_size))
	{
		solution = update_solution(solution, "sa");
		perform_op("sa", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		solution = update_solution(solution, "rra");
		perform_op("rra", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
	}
	else
	{
		solution = update_solution(solution, "rra");
		perform_op("rra", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
	}
	return (solution);
}

char		*handle_three(char *solution, t_super_stack *super_stack)
{
	int		min_num;
	int		*nums;

	nums = super_stack->stack_a->nums;
	find_min(super_stack->stack_a);
	min_num = super_stack->stack_a->min_num;
	if (min_num == nums[0])
		solution = handle_three_a(solution, super_stack);
	else if (min_num == nums[1])
		solution = handle_three_b(solution, super_stack);
	else
		solution = handle_three_c(solution, super_stack);
	return (solution);
}

char		*handle_small_stack(char *solution,
								t_super_stack *super_stack)
{
	if (super_stack->stack_a->cur_size == 2)
	{
		if (super_stack->stack_a->nums[0] > super_stack->stack_a->nums[1])
		{
			solution = update_solution(solution, "sa");
			perform_op("sa", super_stack->stack_a,
						super_stack->stack_b, super_stack->flags);
		}
	}
	else if (!is_sorted(super_stack->stack_a->nums,
				super_stack->stack_a->cur_size))
		solution = handle_three(solution, super_stack);
	return (solution);
}
