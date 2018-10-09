/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmtana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:17:55 by mmtana            #+#    #+#             */
/*   Updated: 2018/08/12 15:17:59 by mmtana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/arrs.h"

int			len_mod_detected(char s)
{
	int		i;

	i = 0;
	while (g_length_mods[i])
	{
		if (g_length_mods[i] == s)
			return (1);
		i++;
	}
	return (0);
}

int			convsp_detected(char s)
{
	int		i;

	i = 0;
	while (g_convsp[i])
	{
		if (g_convsp[i] == s)
			return (1);
		i++;
	}
	return (0);
}

int			flag_detected(char s)
{
	int		i;

	i = 0;
	while (g_flags[i])
	{
		if (g_flags[i] == s)
			return (1);
		i++;
	}
	return (0);
}

int			second_quote(char *fmt)
{
	while (*fmt)
	{
		fmt++;
		if (*fmt == '%')
			return (1);
	}
	return (0);
}
