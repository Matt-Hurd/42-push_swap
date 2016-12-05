/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:43:19 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 16:44:21 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	ps;
	int		tmp;

	setup_env(&ps, ac, av);
	if (is_sort(&ps))
		return (1);
	else if ((tmp = check_rotates(&ps)) != 0)
		only_rotate(&ps, tmp);
	else if (check_swaps(&ps) == 1)
		only_swaps(&ps);
	else if (ps.a_len <= 6)
		merge_sort(&ps);
	else
		slow_sort(&ps);
	return (0);
}
