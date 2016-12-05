/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:47:42 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 16:08:36 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps, char swap)
{
	int	tmp;

	if (ps->a_len <= 1)
		return ;
	tmp = ps->a[ps->a_len - 1];
	ps->a[ps->a_len - 1] = ps->a[ps->a_len - 2];
	ps->a[ps->a_len - 2] = tmp;
	if (swap)
		ft_putstr("sa\n");
	debug_print(ps);
}

void	sb(t_ps *ps, char swap)
{
	int	tmp;

	if (ps->b_len <= 1)
		return ;
	tmp = ps->b[ps->b_len - 1];
	ps->b[ps->b_len - 1] = ps->b[ps->b_len - 2];
	ps->b[ps->b_len - 2] = tmp;
	if (swap)
		ft_putstr("sb\n");
	debug_print(ps);
}

void	ss(t_ps *ps, char swap)
{
	sa(ps, 0);
	sb(ps, 0);
	if (swap)
		ft_putstr("ss\n");
	debug_print(ps);
}
