/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:08:10 by diego             #+#    #+#             */
/*   Updated: 2023/06/02 17:26:26 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_reverse(t_intl **st_b)
{
	if ((*st_b)->content < (*st_b)->next->content
		&& (*st_b)->next->content > (*st_b)->next->next->content
		&& (*st_b)->content > (*st_b)->next->next->content)
		do_s(st_b, 'b');
	else if ((*st_b)->content < (*st_b)->next->content
		&& (*st_b)->next->content < (*st_b)->next->next->content
		&& (*st_b)->content < (*st_b)->next->next->content)
	{
		do_s(st_b, 'b');
		do_rrx(st_b, 'b');
	}
	else if ((*st_b)->content < (*st_b)->next->content
		&& (*st_b)->next->content > (*st_b)->next->next->content
		&& (*st_b)->content < (*st_b)->next->next->content)
		do_r(st_b, 'b');
	else if ((*st_b)->content > (*st_b)->next->content
		&& (*st_b)->next->content < (*st_b)->next->next->content
		&& (*st_b)->content > (*st_b)->next->next->content)
	{
		do_s(st_b, 'b');
		do_r(st_b, 'b');
	}
	else
		do_rrx(st_b, 'b');
}

void	ft_five_reverse(t_intl **st_a, t_intl **st_b, int size)
{
	if (!intlist_ordered_reverse(st_b))
	{
		if (size == 4)
		{
			while (intlist_biggest(st_b) != (*st_b)->content)
				do_r(st_b, 'b');
			do_p(st_b, st_a, 'a');
			if (!intlist_ordered_reverse(st_b))
				ft_three_reverse(st_b);
			do_p(st_b, st_a, 'a');
		}
		else
		{
			while (intlist_biggest(st_b) != (*st_b)->content)
				do_r(st_b, 'b');
			do_p(st_b, st_a, 'a');
			while (intlist_biggest(st_b) != (*st_b)->content)
				do_r(st_b, 'b');
			do_p(st_b, st_a, 'a');
			if (!intlist_ordered(st_b))
				ft_three_reverse(st_b);
			do_p(st_a, st_b, 'b');
			do_p(st_a, st_b, 'b');
		}
	}
}

void	ft_order_smallest(t_intl **st_a, t_intl **st_b, int size, int min_a)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*st_b)->content < (*st_b)->next->content)
			do_s(st_b, 'b');
	}
	else if (size == 3)
		ft_three_reverse(st_b);
	else if (size < 6)
		ft_five_reverse(st_a, st_b, size);
	while ((*st_a)->content < min_a)
		do_p(st_a, st_b, 'b');
}
