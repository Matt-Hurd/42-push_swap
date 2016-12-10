/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:42:46 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 19:50:22 by mhurd            ###   ########.fr       */
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
		if (i_min == 0)
			pb(ps, 1);
		else if (i_min == 1)
			sa(ps, 1);
		else if (i_min <= ps->a_len / 2)
			ra(ps, 1);
		else if (i_min > ps->a_len / 2)
			rra(ps, 1);
	}
	while (ps->b_len)
		pa(ps, 1);
}

void	test_slow_sort(t_ps *ps)
{
	int		i_min;

	i_min = 0;
	while (ps->ta_len)
	{
		i_min = find_min_i(ps->ta, ps->ta_len);
		if (i_min == 0)
			tpb(ps, 1);
		else if (i_min == 1)
			tsa(ps, 1);
		else if (i_min <= ps->a_len / 2)
			tra(ps, 1);
		else if (i_min > ps->a_len / 2)
			trra(ps, 1);
	}
	while (ps->b_len)
		tpa(ps, 1);
}
