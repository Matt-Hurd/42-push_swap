/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 01:03:04 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 16:08:32 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *ps, char swap)
{
	int	tmp;
	int i;

	if (ps->a_len <= 1)
		return ;
	tmp = ps->a[0];
	i = -1;
	while (++i < ps->a_len - 1)
		ps->a[i] = ps->a[i + 1];
	ps->a[ps->a_len - 1] = tmp;
	if (swap)
		ft_putstr("rra\n");
	debug_print(ps);
}

void	rrb(t_ps *ps, char swap)
{
	int	tmp;
	int i;

	if (ps->b_len <= 1)
		return ;
	tmp = ps->b[0];
	i = -1;
	while (++i < ps->b_len - 2)
		ps->b[i] = ps->b[i + 1];
	ps->b[ps->b_len - 1] = tmp;
	if (swap)
		ft_putstr("rrb\n");
	debug_print(ps);
}

void	rrr(t_ps *ps, char swap)
{
	rra(ps, 0);
	rrb(ps, 0);
	if (swap)
		ft_putstr("rrr\n");
	debug_print(ps);
}
