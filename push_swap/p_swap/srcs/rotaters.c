/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:52:23 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/22 18:52:25 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char		*reverse_rotations(char *solution, t_super_stack *super_stack)
{
	while (((super_stack->moves->rrb)) && ((super_stack->moves->rra)))
	{
		solution = update_solution(solution, "rrr");
		perform_op("rrr", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		(super_stack->moves->rra)--;
		(super_stack->moves->rrb)--;
	}
	while (((super_stack->moves->rrb)))
	{
		solution = update_solution(solution, "rrb");
		perform_op("rrb", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		(super_stack->moves->rrb)--;
	}
	while (((super_stack->moves->rra)))
	{
		solution = update_solution(solution, "rra");
		perform_op("rra", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		(super_stack->moves->rra)--;
	}
	return (solution);
}

char		*forward_rotations(char *solution, t_super_stack *super_stack)
{
	while (((super_stack->moves->rb)) && ((super_stack->moves->ra)))
	{
		solution = update_solution(solution, "rr");
		perform_op("rr", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		(super_stack->moves->ra)--;
		(super_stack->moves->rb)--;
	}
	while (((super_stack->moves->rb)))
	{
		solution = update_solution(solution, "rb");
		perform_op("rb", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		(super_stack->moves->rb)--;
	}
	while (((super_stack->moves->ra)))
	{
		solution = update_solution(solution, "ra");
		perform_op("ra", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		(super_stack->moves->ra)--;
	}
	return (solution);
}
