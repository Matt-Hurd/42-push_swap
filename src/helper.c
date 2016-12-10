/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 01:44:23 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/10 10:56:26 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		debug_print(t_ps *ps)
{
	int i;

	if (!ps->debug)
		return (0);
	ft_putstr(RED);
	ft_putendl("Stack A:");
	i = ps->a_len;
	ft_putstr(GREEN);
	while (i--)
		ft_putendl(ft_itoa(ps->a[i]));
	ft_putstr(RED);
	ft_putendl("Stack B:");
	i = ps->b_len;
	ft_putstr(BLUE);
	while (i--)
		ft_putendl(ft_itoa(ps->b[i]));
	ft_putendl("");
	ft_putstr(NC);
	return (0);
}

int		check_duplicates(t_ps *ps)
{
	int		x;
	int		y;

	x = -1;
	while (++x < ps->a_len)
	{
		y = -1;
		while (++y < ps->a_len)
			if (x != y && ps->a[x] == ps->a[y])
				return (-1);
	}
	return (0);
}

int		handle_options(int *ac, char ***av, t_ps *ps)
{
	if (*ac > 1 && ft_strequ((*av)[1], "-d"))
	{
		ps->a_len--;
		(*ac)--;
		(*av)++;
		return ((ps->debug = 1));
	}
	return (0);
}

int		handle_args(int ac, char **av, t_ps *ps)
{
	int		i;
	int		x;
	long	tmp;

	handle_options(&ac, &av, ps);
	i = 0;
	while (++i < ac)
	{
		x = -1;
		while (av[i][++x])
			if ((!ft_isdigit(av[i][x])) && !(av[i][x] == '-' && x == 0))
				return (-1);
		if (x == 0)
			return (-1);
		if (x > 11)
			return (-1);
		tmp = ft_atol(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (-1);
		ps->a[ac - 1 - i] = (int)tmp;
	}
	return (0);
}

void	setup_env(t_ps *ps, int ac, char **av)
{
	ps->a = ft_memalloc(sizeof(int) * (ac - 1));
	ps->b = ft_memalloc(sizeof(int) * (ac - 1));
	ps->ta = ft_memalloc(sizeof(int) * (ac - 1));
	ps->tb = ft_memalloc(sizeof(int) * (ac - 1));
	ps->a_len = ac - 1;
	if (handle_args(ac, av, ps) || check_duplicates(ps))
	{
		free(ps->a);
		free(ps->b);
		free(ps->ta);
		free(ps->tb);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
