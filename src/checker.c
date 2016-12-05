/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:43:48 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 16:08:47 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		handle_instruction(t_ps *ps, char *line)
{
	if (ft_strequ(line, "sa"))
		sa(ps, 0);
	else if (ft_strequ(line, "sb"))
		sb(ps, 0);
	else if (ft_strequ(line, "ss"))
		ss(ps, 0);
	else if (ft_strequ(line, "pa"))
		pa(ps, 0);
	else if (ft_strequ(line, "pb"))
		pb(ps, 0);
	else if (ft_strequ(line, "ra"))
		ra(ps, 0);
	else if (ft_strequ(line, "rb"))
		rb(ps, 0);
	else if (ft_strequ(line, "rr"))
		rr(ps, 0);
	else if (ft_strequ(line, "rra"))
		rra(ps, 0);
	else if (ft_strequ(line, "rrb"))
		rrb(ps, 0);
	else if (ft_strequ(line, "rrr"))
		rrr(ps, 0);
	else
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_ps	ps;
	char	*line;

	setup_env(&ps, ac, av);
	while (ft_get_next_line(1, &line) > 0)
		if (handle_instruction(&ps, line))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	if (is_sort(&ps))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
