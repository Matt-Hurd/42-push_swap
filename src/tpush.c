/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:54:31 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 18:47:50 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tpa(t_ps *ps, char swap)
{
	if (ps->tb_len == 0)
		return ;
	ps->ta[ps->ta_len] = ps->tb[ps->tb_len - 1];
	ps->tb[ps->tb_len - 1] = 0;
	ps->ta_len++;
	ps->tb_len--;
	if (swap)
		ps->t_len++;
}

void	tpb(t_ps *ps, char swap)
{
	if (ps->ta_len == 0)
		return ;
	ps->tb[ps->tb_len] = ps->ta[ps->ta_len - 1];
	ps->ta[ps->ta_len - 1] = 0;
	ps->tb_len++;
	ps->ta_len--;
	if (swap)
		ps->t_len++;
}
