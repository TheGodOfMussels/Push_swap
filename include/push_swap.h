/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:37:53 by dimolin2          #+#    #+#             */
/*   Updated: 2023/06/06 00:38:55 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include "libft.h"
# include "libftprintf.h"
# include "get_next_line.h"

// check and make functions
int		ft_check_and_make(int ac, char **av, t_intl **st_a);
int		ft_check_valid(char *str);
int		*ft_tab_create(int ac, char **av);
int		*ft_bubblesort_tab(int *tab, int ac);
int		ft_check_rep(int *tab, int ac);
int		ft_stacker(t_intl **st_a, int ac, int *tab, int *ordered);
int		ft_pick_converted(int n, int *ordered, int ac);

// algorithm functions
void	ft_algorithm_selector(t_intl **st_a, t_intl **st_b, int ac);
void	ft_algorithm_three(t_intl **st_a);
void	ft_algorithm_five(t_intl **st_a, t_intl **st_b);
void	ft_sixplus_algorithm(t_intl **st_a, t_intl **st_b);
void	ft_sort_in_b(t_intl **st_a, t_intl **st_b, int **pivets, int *sector);
void	ft_sort_in_b_utils(t_intl **st_a, t_intl **st_b, int pivot, int piv_b);
void	ft_resort_from_bottom(t_intl **st_b, int piv_b);
void	ft_reverse_sort(t_intl **st_a, t_intl **st_b, int pivot);
void	ft_sort_last_two(t_intl **st_a, t_intl **st_b,
			int **pivets, int *sector);
void	ft_sort_in_b_2(t_intl **st_a, t_intl **st_b, int **pivets, int *sector);
void	ft_sixplus_algorithm2(t_intl **st_a, t_intl **st_b);

//algorithm utils functions
void	ft_resort_bottom_byone(t_intl **st_a, t_intl **st_b, int pivot);
void	ft_sort_bottom(t_intl **st_a, t_intl **st_b);
void	ft_sort_last_two_utils(t_intl **st_a, t_intl **st_b,
			int pivot, int piv_b);
void	ft_order_smallest(t_intl **st_a, t_intl **st_b, int size, int min_a);
void	ft_three_reverse(t_intl **st_b);
void	ft_five_reverse(t_intl **st_a, t_intl **st_b, int size);

// operations functions
void	do_p(t_intl **stack, t_intl **dest, char push);
void	do_r(t_intl **stack, char rot);
void	do_rr(t_intl **stack_a, t_intl **stack_b);
void	do_rrb(t_intl **stack_b);
void	do_rrx(t_intl **stack, char rev);
void	do_rrr(t_intl **stack_a, t_intl **stack_b);
void	do_rrr2(t_intl **stack_b);
void	do_s(t_intl **stack, char swap);
void	do_ss(t_intl **stack_a, t_intl **stack_b);

// utils functions
void	ft_error_msg(void);
int		*ft_tab_attach_two(int *tab, int second, int first, int sector);
int		intlist_is_under(t_intl **list, int value);
int		intlist_is_over(t_intl **list, int value);

#endif
