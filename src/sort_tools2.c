/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 00:13:56 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/05 00:24:45 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_mid(int *arr, int len)
{
	int		copy[len];
	int		x;
	int		y;

	x = -1;
	while (++x < len)
	{
		copy[x] = INT_MAX;
		y = -1;
		while (++y < len)
			if (arr[y] < copy[x] && (x == 0 || copy[x - 1] < arr[y]))
				copy[x] = arr[y];
	}
	return (copy[len / 2]);
}
