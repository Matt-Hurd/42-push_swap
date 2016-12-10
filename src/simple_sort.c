/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 03:23:28 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/05 00:26:17 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_swaps(t_ps *ps)
{
	int		i_swap;
	int		cpt;
	int		tmp;

	i_swap = 0;
	while (i_swap != -1)
	{
		i_swap = get_swap(ps->a, ps->a_len);
		cpt = i_swap;
		while (cpt <= ps->a_len / 2 ? cpt-- > 0 : cpt++ < ps->a_len)
			i_swap <= ps->a_len / 2 ? ra(ps, 1) : rra(ps, 1);
		if (ps->a[ps->a_len - 1] > ps->a[ps->a_len - 2])
			sa(ps, 1);
		cpt = i_swap;
		while (cpt <= ps->a_len / 2 ? cpt-- > 0 : cpt++ < ps->a_len)
			i_swap <= ps->a_len / 2 ? rra(ps, 1) : ra(ps, 1);
		if ((tmp = check_rotates(ps)) != 0)
		{
			only_rotate(ps, tmp);
			break ;
		}
	}
}

void	only_rotate(t_ps *ps, int rotates)
{
	if (rotates <= ps->a_len / 2)
		while (rotates-- > 0)
			ra(ps, 1);
	else
		while (rotates++ < ps->a_len)
			rra(ps, 1);
}

void	sort_a(t_ps *ps)
{
	int		max_i;

	max_i = find_max_i(ps->a, ps->a_len);
	if (max_i == 0)
		ra(ps, 1);
	if (max_i == 1)
		rra(ps, 1);
	if (ps->a[ps->a_len - 1] > ps->a[ps->a_len - 2])
		sa(ps, 1);
}

void	sort_b(t_ps *ps)
{
	int		max_i;

	if (ps->b_len == 1)
		return ;
	if (ps->b_len == 2)
	{
		if (ps->b[ps->b_len - 1] > ps->b[ps->b_len - 2])
			sb(ps, 1);
		return ;
	}
	else if (ps->b_len == 3)
	{
		max_i = find_max_i(ps->b, ps->b_len);
		if (max_i == 0)
			rb(ps, 1);
		if (max_i == 1)
			rrb(ps, 1);
		if (ps->b[ps->b_len - 1] > ps->b[ps->b_len - 1])
			sb(ps, 1);
	}
}

void	simple_merge_sort(t_ps *ps)
{
	int		max;
	int		min;

	while (ps->a_len > 3)
		pb(ps, 1);
	sort_a(ps);
	sort_b(ps);
	while (ps->b_len)
	{
		max = find_max(ps->a, ps->a_len);
		min = find_min(ps->a, ps->a_len);
		if (ps->b[ps->b_len - 1] < ps->a[ps->a_len - 1] ||
			(ps->b[ps->b_len - 1] > max && ps->a[ps->a_len - 1] == min))
			pa(ps, 1);
		ra(ps, 1);
	}
	min = find_min(ps->a, ps->a_len);
	while (ps->a[ps->a_len - 1] != min)
		ra(ps, 1);
}
