/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 01:44:23 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/10 11:09:31 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	close_env(t_ps *ps)
{
	t_list *tmp;
	t_list *prev;

	free(ps->a);
	free(ps->b);
	tmp = ps->sorts;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->content);
		free(prev);
	}
	free(ps->ta);
	free(ps->tb);
}
