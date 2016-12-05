/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:58:26 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 16:08:28 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps, char swap)
{
	int	tmp;
	int i;

	if (ps->a_len <= 1)
		return ;
	tmp = ps->a[ps->a_len - 1];
	i = ps->a_len;
	while (--i > 0)
		ps->a[i] = ps->a[i - 1];
	ps->a[0] = tmp;
	if (swap)
		ft_putstr("ra\n");
	debug_print(ps);
}

void	rb(t_ps *ps, char swap)
{
	int	tmp;
	int i;

	if (ps->b_len <= 1)
		return ;
	tmp = ps->b[ps->b_len - 1];
	i = ps->b_len;
	while (--i > 0)
		ps->b[i] = ps->b[i - 1];
	ps->b[0] = tmp;
	if (swap)
		ft_putstr("rb\n");
	debug_print(ps);
}

void	rr(t_ps *ps, char swap)
{
	ra(ps, 0);
	rb(ps, 0);
	if (swap)
		ft_putstr("rr\n");
	debug_print(ps);
}
