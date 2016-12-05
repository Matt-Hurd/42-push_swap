/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 03:02:58 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 15:32:56 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_swaps(t_ps *ps)
{
	int		nb_swaps;
	int		i;

	nb_swaps = 0;
	i = -1;
	while (++i < ps->a_len - 2)
		if (ps->a[i] < ps->a[i + 1])
			nb_swaps++;
	return (nb_swaps);
}

int		check_rotates(t_ps *ps)
{
	int		i;
	int		last;

	i = ps->a_len;
	last = 0;
	while (--i > 0)
	{
		if (ps->a[i] > ps->a[i - 1])
		{
			i--;
			break ;
		}
		last++;
	}
	while (i > 0)
	{
		if (ps->a[i] > ps->a[ps->a_len - 1] || ps->a[i] > ps->a[i - 1])
			return (0);
		i--;
	}
	return (ps->a[i] < ps->a[ps->a_len - 1] ? last + 1 : 0);
}

int		is_sort(t_ps *ps)
{
	int i;

	if (ps->b_len)
		return (0);
	i = -1;
	while (++i < ps->a_len - 1)
		if (ps->a[i] < ps->a[i + 1])
			return (0);
	return (1);
}
