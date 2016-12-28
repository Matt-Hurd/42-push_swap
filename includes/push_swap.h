/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:39:20 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/28 08:06:34 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# include <stdlib.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define NC "\033[0m"
# define ABS(x) ((x) < 0 ? (-x) : (x))

enum			e_sort
{
	MERGE,
	ROTATE,
	SWAP,
	SLOW
};

typedef struct	s_sort
{
	int		len;
	int		type;
}				t_sort;

typedef struct	s_ps
{
	int		*a;
	int		*b;
	int		*ta;
	int		*tb;
	int		a_len;
	int		b_len;
	int		ta_len;
	int		tb_len;
	int		t_len;
	t_list	*sorts;
	char	debug : 1;
	char	color : 1;
	char	printsort : 1;
	char	printlen : 1;
	char	printslow : 1;
	int		len;
}				t_ps;

void			setup_env(t_ps *ps, int ac, char **av);
int				is_sort(t_ps *ps);
void			only_rotate(t_ps *ps, int rotates);
void			only_swaps(t_ps *ps);
int				get_swap(int *arr, int len);
int				check_swaps(t_ps *ps);
int				check_rotates(t_ps *ps);
int				find_max(int *arr, int len);
int				find_min(int *arr, int len);
int				find_max_i(int *arr, int len);
int				find_min_i(int *arr, int len);
void			simple_merge_sort(t_ps *ps);
int				debug_print(t_ps *ps);
void			slow_sort(t_ps *ps);
int				find_mid(int *arr, int len);
void			merge_sort(t_ps *ps);
int				is_stack_sort(int *arr, int len, char rev);
int				*find_len(t_ps *ps, int x);
int				find_pos(int *arr, int len, int val);
void			close_env(t_ps *ps);
void			set_len_vals(t_ps *ps, int *len, int y);
void			rotate_individuals(t_ps *ps, int *len);
void			sort_big_a_on_b(t_ps *ps, int len, int x, int *tmp);
void			do_sort(t_ps *ps, int *len);

void			pb(t_ps *ps, char swap);
void			pa(t_ps *ps, char swap);
void			sa(t_ps *ps, char swap);
void			sb(t_ps *ps, char swap);
void			ss(t_ps *ps, char swap);
void			ra(t_ps *ps, char swap);
void			rb(t_ps *ps, char swap);
void			rr(t_ps *ps, char swap);
void			rra(t_ps *ps, char swap);
void			rrb(t_ps *ps, char swap);
void			rrr(t_ps *ps, char swap);

void			tpb(t_ps *ps, char swap);
void			tpa(t_ps *ps, char swap);
void			tsa(t_ps *ps, char swap);
void			tsb(t_ps *ps, char swap);
void			tss(t_ps *ps, char swap);
void			tra(t_ps *ps, char swap);
void			trb(t_ps *ps, char swap);
void			trr(t_ps *ps, char swap);
void			trra(t_ps *ps, char swap);
void			trrb(t_ps *ps, char swap);
void			trrr(t_ps *ps, char swap);

void			test_only_rotate(t_ps *ps, int rotates);
void			test_only_swaps(t_ps *ps);
void			test_simple_merge_sort(t_ps *ps);
void			test_slow_sort(t_ps *ps);

#endif
