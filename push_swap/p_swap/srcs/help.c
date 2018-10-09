/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:50:29 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/22 18:50:33 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		print_spaces(int spaces)
{
	while (spaces--)
		ft_printf(" ");
}

int			longest_int_len(t_stack *stack_a)
{
	int		longest;
	size_t	len;
	int		i;

	longest = stack_a->nums[0];
	len = ft_int_len(longest);
	i = 1;
	while (i < stack_a->cur_size)
	{
		if (ft_int_len(stack_a->nums[i]) > len)
		{
			longest = stack_a->nums[i];
			len = ft_int_len(stack_a->nums[i]);
		}
		i++;
	}
	if (longest < 0)
		len++;
	return (len);
}
