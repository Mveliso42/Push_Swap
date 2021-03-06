/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:18:54 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/12 16:18:56 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		handle_hash_flag(t_pf_detective *pf)
{
	if ((pf->convsp == 'o' || pf->convsp == 'O')
			&& (pf->unsigned_int_holder || pf->pr_flag))
	{
		ft_putstr("0");
		pf->printed++;
	}
	else if (pf->convsp == 'x' && pf->unsigned_int_holder)
	{
		ft_putstr("0x");
		pf->printed += 2;
	}
	else if (pf->convsp == 'X' && pf->unsigned_int_holder)
	{
		ft_putstr("0X");
		pf->printed += 2;
	}
}

void		handle_space_flag(t_pf_detective *pf)
{
	write(1, " ", 1);
	pf->printed++;
}

void		handle_plus_flag(t_pf_detective *pf)
{
	write(1, "+", 1);
	pf->printed++;
}

void		handle_flags(t_pf_detective *pf)
{
	int		i;

	i = 0;
	while (pf->flags[i])
	{
		if (pf->flags[i] == '#')
			handle_hash_flag(pf);
		else if (pf->flags[i] == ' ' &&
				((pf->convsp == 'd' || pf->convsp == 'i')
					&& pf->signed_int_holder >= 0) && !pf->plus_flag)
			handle_space_flag(pf);
		else if (pf->flags[i] == '+'
			&& (pf->convsp == 'd' || pf->convsp == 'i')
			&& (pf->signed_int_holder >= 0) && pf->plus_flag)
			handle_plus_flag(pf);
		i++;
	}
}
