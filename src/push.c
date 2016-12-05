/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:54:31 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 16:08:24 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps, char swap)
{
	if (ps->b_len == 0)
		return ;
	ps->a[ps->a_len] = ps->b[ps->b_len - 1];
	ps->b[ps->b_len - 1] = 0;
	ps->a_len++;
	ps->b_len--;
	if (swap)
		ft_putstr("pa\n");
	debug_print(ps);
}

void	pb(t_ps *ps, char swap)
{
	if (ps->a_len == 0)
		return ;
	ps->b[ps->b_len] = ps->a[ps->a_len - 1];
	ps->a[ps->a_len - 1] = 0;
	ps->b_len++;
	ps->a_len--;
	if (swap)
		ft_putstr("pb\n");
	debug_print(ps);
}
