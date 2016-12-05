/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:42:46 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 17:01:37 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	slow_sort(t_ps *ps)
{
	int		i_min;

	i_min = 0;
	while (ps->a_len)
	{
		i_min = find_min_i(ps->a, ps->a_len);
		if (i_min > (1 + ps->a_len / 2))
			while (i_min++ < ps->a_len)
				rra(ps, 1);
		else
			while (i_min-- > 0)
				ra(ps, 1);
		pb(ps, 1);
	}
	while (ps->b_len)
		pa(ps, 1);
}
