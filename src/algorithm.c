/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:01:57 by diego             #+#    #+#             */
/*   Updated: 2023/06/06 00:35:16 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm_three(t_intl **st_a)
{
	if ((*st_a)->content > (*st_a)->next->content
		&& (*st_a)->next->content < (*st_a)->next->next->content
		&& (*st_a)->content < (*st_a)->next->next->content)
		do_s(st_a, 'a');
	else if ((*st_a)->content > (*st_a)->next->content
		&& (*st_a)->next->content > (*st_a)->next->next->content
		&& (*st_a)->content > (*st_a)->next->next->content)
	{
		do_s(st_a, 'a');
		do_rrx(st_a, 'a');
	}
	else if ((*st_a)->content > (*st_a)->next->content
		&& (*st_a)->next->content < (*st_a)->next->next->content
		&& (*st_a)->content > (*st_a)->next->next->content)
		do_r(st_a, 'a');
	else if ((*st_a)->content < (*st_a)->next->content
		&& (*st_a)->next->content > (*st_a)->next->next->content
		&& (*st_a)->content < (*st_a)->next->next->content)
	{
		do_s(st_a, 'a');
		do_r(st_a, 'a');
	}
	else
		do_rrx(st_a, 'a');
}

void	ft_algorithm_five(t_intl **st_a, t_intl **st_b)
{
	if (!intlist_ordered(st_a))
	{
		if (intlist_lenght(st_a) == 4)
		{
			while (intlist_smallest(st_a) != (*st_a)->content)
				do_r(st_a, 'a');
			do_p(st_a, st_b, 'b');
			if (!intlist_ordered(st_a))
				ft_algorithm_three(st_a);
			do_p(st_b, st_a, 'a');
		}
		else
		{
			while (intlist_smallest(st_a) != (*st_a)->content)
				do_r(st_a, 'a');
			do_p(st_a, st_b, 'b');
			while (intlist_smallest(st_a) != (*st_a)->content)
				do_r(st_a, 'a');
			do_p(st_a, st_b, 'b');
			if (!intlist_ordered(st_a))
				ft_algorithm_three(st_a);
			do_p(st_b, st_a, 'a');
			do_p(st_b, st_a, 'a');
		}
	}
}

void	ft_algorithm_selector(t_intl **st_a, t_intl **st_b, int ac)
{
	if (intlist_ordered(st_a))
		return ;
	else if (ac == 2)
	{
		if ((*st_a)->content > (*st_a)->next->content)
			do_s(st_a, 'a');
	}
	else if (ac == 3)
		ft_algorithm_three(st_a);
	else if (ac < 6)
		ft_algorithm_five(st_a, st_b);
	else if (ac >= 6 && ac < 250)
		ft_sixplus_algorithm(st_a, st_b);
	else
		ft_sixplus_algorithm2(st_a, st_b);
}
