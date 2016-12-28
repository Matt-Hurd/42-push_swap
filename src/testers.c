/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:10:23 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/28 10:39:06 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_only_swaps(t_ps *ps)
{
	int		i_swap;
	int		cpt;
	int		tmp;

	i_swap = 0;
	while (i_swap != -1)
	{
		i_swap = get_swap(ps->ta, ps->ta_len);
		cpt = i_swap;
		while (cpt <= ps->ta_len / 2 ? cpt-- > 0 : cpt++ < ps->ta_len)
			i_swap <= ps->ta_len / 2 ? tra(ps, 1) : trra(ps, 1);
		if (ps->ta[ps->ta_len - 1] > ps->ta[ps->ta_len - 2])
			tsa(ps, 1);
		cpt = i_swap;
		while (cpt <= ps->ta_len / 2 ? cpt-- > 0 : cpt++ < ps->ta_len)
			i_swap <= ps->ta_len / 2 ? trra(ps, 1) : tra(ps, 1);
		if ((tmp = check_rotates(ps)) != 0)
		{
			test_only_rotate(ps, tmp);
			break ;
		}
	}
}

void	test_only_rotate(t_ps *ps, int rotates)
{
	if (rotates <= ps->ta_len / 2)
		while (rotates-- > 0)
			tra(ps, 1);
	else
		while (rotates++ < ps->ta_len)
			trra(ps, 1);
}

void	test_sort_a(t_ps *ps)
{
	int		max_i;

	max_i = find_max_i(ps->ta, ps->ta_len);
	if (max_i == 0)
		tra(ps, 1);
	if (max_i == 1)
		trra(ps, 1);
	if (ps->ta[ps->ta_len - 1] > ps->ta[ps->ta_len - 2])
		tsa(ps, 1);
}

void	test_sort_b(t_ps *ps)
{
	int		max_i;

	if (ps->tb_len == 1)
		return ;
	if (ps->tb_len == 2)
	{
		if (ps->tb[ps->tb_len - 1] > ps->tb[ps->tb_len - 2])
			tsb(ps, 1);
		return ;
	}
	else if (ps->tb_len == 3)
	{
		max_i = find_max_i(ps->tb, ps->tb_len);
		if (max_i == 0)
			trb(ps, 1);
		if (max_i == 1)
			trrb(ps, 1);
		if (ps->tb[ps->tb_len - 1] > ps->tb[ps->tb_len - 1])
			tsb(ps, 1);
	}
}

void	test_simple_merge_sort(t_ps *ps)
{
	int		max;
	int		min;

	while (ps->ta_len > 3)
		tpb(ps, 1);
	test_sort_a(ps);
	test_sort_b(ps);
	while (ps->tb_len)
	{
		max = find_max(ps->ta, ps->ta_len);
		min = find_min(ps->ta, ps->ta_len);
		if (ps->tb[ps->tb_len - 1] < ps->ta[ps->ta_len - 1] ||
			(ps->tb[ps->tb_len - 1] > max && ps->ta[ps->ta_len - 1] == min))
			tpa(ps, 1);
		tra(ps, 1);
	}
	min = find_min(ps->ta, ps->ta_len);
	while (ps->ta[ps->ta_len - 1] != min)
		tra(ps, 1);
}
