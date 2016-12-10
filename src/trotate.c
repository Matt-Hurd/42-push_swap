/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:58:26 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 18:47:58 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tra(t_ps *ps, char swap)
{
	int	tmp;
	int i;

	if (ps->ta_len <= 1)
		return ;
	tmp = ps->ta[ps->ta_len - 1];
	i = ps->ta_len;
	while (--i > 0)
		ps->ta[i] = ps->ta[i - 1];
	ps->ta[0] = tmp;
	if (swap)
		ps->t_len++;
}

void	trb(t_ps *ps, char swap)
{
	int	tmp;
	int i;

	if (ps->tb_len <= 1)
		return ;
	tmp = ps->tb[ps->tb_len - 1];
	i = ps->tb_len;
	while (--i > 0)
		ps->tb[i] = ps->tb[i - 1];
	ps->tb[0] = tmp;
	if (swap)
		ps->t_len++;
}

void	trr(t_ps *ps, char swap)
{
	(void)swap;
	tra(ps, 0);
	trb(ps, 0);
	ps->t_len++;
}
