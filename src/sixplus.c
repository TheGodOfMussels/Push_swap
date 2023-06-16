/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:12:10 by diego             #+#    #+#             */
/*   Updated: 2023/06/06 00:50:54 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_last_two(t_intl **st_a, t_intl **st_b,
			int **pivets, int *sector)
{
	int	*prev_piv;
	int	pivot;
	int	piv_b;
	int	size;

	prev_piv = NULL;
	size = intlist_lenght(st_b);
	if (size < 6)
		return ;
	if (*sector != 0)
		prev_piv = *pivets;
	pivot = intlist_get_average(st_b);
	piv_b = (pivot + intlist_biggest(st_b)) / 2;
	pivot = (intlist_biggest(st_b) + piv_b) / 2;
	*pivets = ft_tab_attach_two(prev_piv, pivot, piv_b, *sector);
	*sector += 2;
	ft_sort_last_two_utils(st_a, st_b, piv_b, pivot);
	ft_sort_last_two(st_a, st_b, pivets, sector);
}

void	ft_resort_from_bottom(t_intl **st_b, int pivot)
{
	do_rrx(st_b, 'b');
	while ((*st_b)->content > pivot)
		do_rrx(st_b, 'b');
	do_r(st_b, 'b');
}

void	ft_sort_in_b(t_intl **st_a, t_intl **st_b, int **pivets, int *sector)
{
	int	*prev_piv;
	int	pivot;
	int	piv_b;

	prev_piv = NULL;
	if (intlist_lenght(st_a) < 6)
		return ;
	if (*sector != 0)
		prev_piv = *pivets;
	piv_b = intlist_get_average(st_a);
	pivot = (piv_b + intlist_smallest(st_a)) / 2;
	*pivets = ft_tab_attach_two(prev_piv, piv_b, pivot, *sector);
	*sector += 2;
	ft_sort_in_b_utils(st_a, st_b, piv_b, pivot);
	ft_resort_from_bottom(st_b, pivot);
	ft_sort_in_b(st_a, st_b, pivets, sector);
}

void	ft_reverse_sort(t_intl **st_a, t_intl **st_b, int pivot)
{
	while (intlist_is_over(st_b, pivot))
	{
		if ((*st_b)->content <= pivot)
			ft_resort_bottom_byone(st_a, st_b, pivot);
		else if ((*st_b)->content == intlist_biggest(st_b))
		{
			do_p(st_b, st_a, 'a');
			ft_sort_bottom(st_a, st_b);
		}
		else if (intlist_lastnode(st_b)->content == intlist_biggest(st_b))
		{
			do_rrx(st_b, 'b');
			do_p(st_b, st_a, 'a');
			ft_sort_bottom(st_a, st_b);
		}
		else if (intlist_lastnode(st_a)->content == intlist_biggest(st_a)
			|| (*st_b)->content > intlist_lastnode(st_a)->content)
		{
			do_p(st_b, st_a, 'a');
			do_r(st_a, 'a');
		}
		else
			do_r(st_b, 'b');
	}
}

void	ft_sixplus_algorithm(t_intl **st_a, t_intl **st_b)
{
	int	*pivets;
	int	sector;
	int	i;

	sector = 0;
	ft_sort_in_b(st_a, st_b, &pivets, &sector);
	ft_algorithm_selector(st_a, st_b, intlist_lenght(st_a));
	while (--sector >= 0)
		ft_reverse_sort(st_a, st_b, pivets[sector]);
	free(pivets);
	sector = 0;
	ft_reverse_sort(st_a, st_b, intlist_dub_smallest(st_a, st_b));
	i = intlist_lenght(st_b);
	while (i-- > 0)
		do_p(st_b, st_a, 'a');
}
