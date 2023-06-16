/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:40:02 by diego             #+#    #+#             */
/*   Updated: 2023/06/02 16:51:07 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bottom(t_intl **st_a, t_intl **st_b)
{
	t_intl	*tmp;

	tmp = intlist_lastnode(st_a);
	if (tmp->content > intlist_biggest(st_b)
		&& tmp->content != intlist_biggest(st_a))
	{
		do_rrx(st_a, 'a');
		ft_sort_bottom(st_a, st_b);
	}
}

void	ft_resort_bottom_byone(t_intl **st_a, t_intl **st_b, int pivot)
{
	t_intl	*a_last;
	int		max_num;

	max_num = intlist_biggest(st_a);
	do_rrx(st_b, 'b');
	while ((*st_b)->content > pivot)
	{
		a_last = intlist_lastnode(st_a);
		if ((*st_b)->content == intlist_biggest(st_b))
		{
			do_p(st_b, st_a, 'a');
			ft_sort_bottom(st_a, st_b);
		}
		else if (a_last->content == max_num
			|| (*st_b)->content > a_last->content)
		{
			do_p(st_b, st_a, 'a');
			do_r(st_a, 'a');
		}
		do_rrx(st_b, 'b');
	}
	do_r(st_b, 'b');
}

void	ft_sort_in_b_utils(t_intl **st_a, t_intl **st_b, int pivot, int piv_b)
{
	while (intlist_is_under(st_a, pivot))
	{
		if ((*st_a)->content <= pivot)
		{
			do_p(st_a, st_b, 'b');
			if ((*st_b)->content > piv_b)
				do_r(st_b, 'b');
		}
		else
			do_r(st_a, 'a');
	}
}

void	ft_sort_last_two_utils(t_intl **st_a, t_intl **st_b,
			int pivot, int piv_b)
{
	int	max;

	max = intlist_biggest(st_a);
	while (intlist_is_over(st_b, pivot))
	{
		if ((*st_b)->content > pivot)
		{
			do_p(st_b, st_a, 'a');
			if ((*st_a)->content <= piv_b)
				do_r(st_a, 'a');
		}
		else
			do_r(st_b, 'b');
	}
	while ((*st_a)->content < max)
		do_rrx(st_a, 'a');
	do_r(st_a, 'a');
}
