/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_make2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:34:07 by diego             #+#    #+#             */
/*   Updated: 2023/05/30 22:59:04 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pick_converted(int n, int *ordered, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ordered[i++] == n)
			return (i);
	}
	ft_error_msg();
	return (0);
}

int	ft_stacker(t_intl **st_a, int ac, int *tab, int *ordered)
{
	t_intl	*tmp;
	int		i;

	tmp = (t_intl *)malloc(sizeof(t_intl));
	if (!tmp)
		return (0);
	tmp->content = ft_pick_converted(tab[0], ordered, ac);
	tmp->next = NULL ;
	(*st_a) = tmp;
	if (!st_a)
		return (0);
	i = 0;
	while (++i < ac)
	{
		(*st_a)->next = intlist_push(ft_pick_converted(tab[i], ordered, ac));
		(*st_a) = (*st_a)->next;
	}
	(*st_a) = tmp;
	free(ordered);
	free(tab);
	return (1);
}
