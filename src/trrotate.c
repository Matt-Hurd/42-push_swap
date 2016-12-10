/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trrotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 01:03:04 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/10 08:35:21 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trra(t_ps *ps, char swap)
{
	int	tmp;
	int i;

	if (ps->ta_len <= 1)
		return ;
	tmp = ps->ta[0];
	i = -1;
	while (++i < ps->ta_len - 1)
		ps->ta[i] = ps->ta[i + 1];
	ps->ta[ps->ta_len - 1] = tmp;
	if (swap)
		ps->t_len++;
}

void	trrb(t_ps *ps, char swap)
{
	int	tmp;
	int i;

	if (ps->tb_len <= 1)
		return ;
	tmp = ps->tb[0];
	i = -1;
	while (++i < ps->tb_len - 1)
		ps->tb[i] = ps->tb[i + 1];
	ps->tb[ps->tb_len - 1] = tmp;
	if (swap)
		ps->t_len++;
}

void	trrr(t_ps *ps, char swap)
{
	(void)swap;
	trra(ps, 0);
	trrb(ps, 0);
	ps->t_len++;
}
