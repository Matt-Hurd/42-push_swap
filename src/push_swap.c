/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:43:19 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/28 10:21:29 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup_test(t_ps *ps, int type)
{
	t_sort	*tmp;

	tmp = (t_sort *)ft_memalloc(sizeof(t_sort));
	tmp->type = type;
	ft_memcpy(ps->ta, ps->a, sizeof(int) * ps->a_len);
	ps->ta_len = ps->a_len;
	ps->tb_len = ps->b_len;
	ft_lstadd(&ps->sorts, ft_lstnew(tmp, sizeof(t_sort)));
	free(tmp);
	ps->t_len = 0;
}

void	cleanup_test(t_ps *ps)
{
	((t_sort *)ps->sorts->content)->len = ps->t_len;
	ps->t_len = 0;
}

void	run_tests(t_ps *ps, int *tmp)
{
	(void)tmp;
	if ((*tmp = check_rotates(ps)) != 0)
	{
		setup_test(ps, ROTATE);
		test_only_rotate(ps, *tmp);
		cleanup_test(ps);
	}
	if (check_swaps(ps) == 1)
	{
		setup_test(ps, SWAP);
		test_only_swaps(ps);
		cleanup_test(ps);
	}
	if (ps->a_len <= 6 && ps->a_len < 50)
	{
		setup_test(ps, MERGE);
		test_simple_merge_sort(ps);
		cleanup_test(ps);
	}
	setup_test(ps, SLOW);
	test_slow_sort(ps);
	cleanup_test(ps);
}

void	do_swaps(t_ps *ps, t_sort *min, int tmp)
{
	if (min->type == 0 && ps->a_len <= 5)
	{
		simple_merge_sort(ps);
		ft_putstr(ps->printsort ? "Sort Used: Simple Sort\n" : "");
	}
	else if (min->type == 1 && ps->a_len == 5)
	{
		only_rotate(ps, tmp);
		ft_putstr(ps->printsort ? "Sort Used: Only Rotates\n" : "");
	}
	else if (min->type == 2)
	{
		only_swaps(ps);
		ft_putstr(ps->printsort ? "Sort Used: Only Swaps\n" : "");
	}
	else
	{
		merge_sort(ps);
		ft_putstr(ps->printsort ? "Sort Used: Merge Sort\n" : "");
	}
	ft_putstr(ps->printlen ? "Operation Count: " : "");
	ps->printlen ? ft_putnbr(ps->len) : ft_putstr("");
	ft_putstr(ps->printlen ? "\n" : "");
}


int		main(int ac, char **av)
{
	t_ps	ps;
	t_list	*lst;
	t_sort	*min;
	int		tmp;

	setup_env(&ps, ac, av);
	if (is_sort(&ps))
	{
		close_env(&ps);
		return (0);
	}
	run_tests(&ps, &tmp);
	lst = ps.sorts;
	min = lst->content;
	while (lst)
	{
		if (min->len > 0 && min->len > ((t_sort *)lst->content)->len)
			min = ((t_sort *)lst->content);
		lst = lst->next;
	}
	do_swaps(&ps, min, tmp);
	close_env(&ps);
	return (0);
}
