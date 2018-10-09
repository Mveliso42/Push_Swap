/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:21:52 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/12 16:21:55 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

int		wide_char_space_left(t_pf_detective *pf, size_t bytes_so_far, size_t i)
{
	if ((pf->wide_str_holder[i + 1]) &&
		((bytes_so_far + ft_wcharlen(pf->wide_str_holder[i + 1])) <
			(unsigned long)ft_atoi(pf->precision)))
		return (1);
	else
		return (0);
}

size_t	widechar_last_len_detective(t_pf_detective *pf)
{
	size_t	i;
	size_t	bytes_so_far;

	if (ft_wcharlen(pf->wide_str_holder[0]) >
			(unsigned long)ft_atoi(pf->precision))
		return (0);
	i = 0;
	bytes_so_far = ft_wcharlen(pf->wide_str_holder[i]);
	while (wide_char_space_left(pf, bytes_so_far, i))
		bytes_so_far += ft_wcharlen(pf->wide_str_holder[++i]);
	return (bytes_so_far);
}
