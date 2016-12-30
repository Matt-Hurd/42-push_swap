/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 03:02:58 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/29 22:56:26 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_swaps(t_ps *ps)
{
	int		nb_swaps;
	int		i;

	nb_swaps = 0;
	i = -1;
	while (++i < ps->a_len - 2)
		if (ps->a[i] < ps->a[i + 1])
			nb_swaps++;
	return (nb_swaps);
}

int		check_rotates(t_ps *ps)
{
	int		i;
	int		last;

	i = ps->a_len;
	last = 0;
	while (--i >= 0)
	{
		if (ps->a[i] > ps->a[i - 1])
		{
			i--;
			break ;
		}
		last++;
	}
	while (i != ps->a_len - 1 - last)
	{
		if (ps->a[i] > ps->a[i - 1] ||
			(i == 0 && ps->a[0] >= ps->a[ps->a_len - 1]))
			return (0);
		i--;
		if (i < 0)
			i = ps->a_len;
	}
	return (ps->a[i] <= ps->a[ps->a_len - 1] ? last + 1 : 0);
}

int		is_stack_sort(int *arr, int len, char rev)
{
	int i;

	i = -1;
	while (++i < len - 1)
		if ((arr[i] < arr[i + 1]) ^ rev)
			return (0);
	return (1);
}

int		is_sort(t_ps *ps)
{
	int i;

	if (ps->b_len)
		return (0);
	i = -1;
	while (++i < ps->a_len - 1)
		if (ps->a[i] < ps->a[i + 1])
			return (0);
	return (1);
}

int		find_pos(int *arr, int len, int val)
{
	int x;

	x = -1;
	while (++x < len)
	{
		if (val < arr[len - 1] && val > arr[0])
			return (x);
		else if (val < arr[len - 1] && arr[0] == find_max(arr, len))
			return (x);
		else if (val > arr[0] && arr[len - 1] == find_min(arr, len))
			return (x);
	}
	return (-1);
}
