/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixplus2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:36:21 by diego             #+#    #+#             */
/*   Updated: 2023/06/06 00:46:50 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_in_b_2(t_intl **st_a, t_intl **st_b, int **pivets, int *sector)
{
	int	*prev_piv;
	int	pivot;
	int	piv_b;

	prev_piv = NULL;
	if (intlist_lenght(st_a) < 6)
		return ;
	if (*sector != 0)
		prev_piv = *pivets;
	pivot = intlist_get_average(st_a);
	piv_b = (pivot + intlist_smallest(st_a)) / 2;
	pivot = (piv_b + intlist_smallest(st_a)) / 2;
	*pivets = ft_tab_attach_two(prev_piv, piv_b, pivot, *sector);
	*sector += 2;
	ft_sort_in_b_utils(st_a, st_b, piv_b, pivot);
	ft_resort_from_bottom(st_b, pivot);
	ft_sort_in_b_2(st_a, st_b, pivets, sector);
}

void	ft_sixplus_algorithm2(t_intl **st_a, t_intl **st_b)
{
	int	*pivets;
	int	sector;
	int	min_a;
	int	i;

	sector = 0;
	ft_sort_in_b_2(st_a, st_b, &pivets, &sector);
	ft_algorithm_selector(st_a, st_b, intlist_lenght(st_a));
	while (--sector > 0)
		ft_reverse_sort(st_a, st_b, pivets[sector]);
	free(pivets);
	sector = 0;
	min_a = intlist_smallest(st_a);
	ft_sort_last_two(st_a, st_b, &pivets, &sector);
	ft_order_smallest(st_a, st_b, intlist_lenght(st_b), min_a);
	i = 0;
	while (i < sector)
		ft_reverse_sort(st_a, st_b, pivets[i++]);
	ft_reverse_sort(st_a, st_b, intlist_smallest(st_b));
	i = intlist_lenght(st_b);
	while (i-- > 0)
		do_p(st_b, st_a, 'a');
	free(pivets);
}
