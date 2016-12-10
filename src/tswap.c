/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:47:42 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 18:48:14 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tsa(t_ps *ps, char swap)
{
	int	tmp;

	if (ps->ta_len <= 1)
		return ;
	tmp = ps->ta[ps->ta_len - 1];
	ps->ta[ps->ta_len - 1] = ps->ta[ps->ta_len - 2];
	ps->ta[ps->ta_len - 2] = tmp;
	if (swap)
		ps->t_len++;
}

void	tsb(t_ps *ps, char swap)
{
	int	tmp;

	if (ps->tb_len <= 1)
		return ;
	tmp = ps->tb[ps->tb_len - 1];
	ps->tb[ps->tb_len - 1] = ps->tb[ps->tb_len - 2];
	ps->tb[ps->tb_len - 2] = tmp;
	if (swap)
		ps->t_len++;
}

void	tss(t_ps *ps, char swap)
{
	(void)swap;
	tsa(ps, 0);
	tsb(ps, 0);
	ps->t_len++;
}
