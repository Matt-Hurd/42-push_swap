/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:39:20 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/04 16:43:54 by mhurd            ###   ########.fr       */
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

#include <stdio.h>




typedef struct	s_ps
{
	int		*a;
	int		*b;
	int		a_len;
	int		b_len;
	char	debug : 1;
}				t_ps;

void			setup_env(t_ps *ps, int ac, char **av);
int				is_sort(t_ps *ps);
void			only_rotate(t_ps *ps, int rotates);
void			only_swaps(t_ps *ps);
int				get_swap(t_ps *ps);
int				check_swaps(t_ps *ps);
int				check_rotates(t_ps *ps);
int				find_max(int *arr, int len);
int				find_min(int *arr, int len);
int				find_max_i(int *arr, int len);
int				find_min_i(int *arr, int len);
void			merge_sort(t_ps *ps);
int				debug_print(t_ps *ps);
void			slow_sort(t_ps *ps);

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

#endif
