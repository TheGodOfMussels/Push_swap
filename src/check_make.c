/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:46:06 by diego             #+#    #+#             */
/*   Updated: 2023/06/06 16:03:07 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
			&& str[i] != '+' && str[i] != ' ')
			return (0);
		else if (str[i] == '-' && ((str[i + 1]) < '0' || str[i + 1] > '9'))
			return (0);
		i++;
	}
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	return (1);
}

int	*ft_tab_create(int ac, char **av)
{
	int	i;
	int	*tab;

	tab = (int *)malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	i = 1;
	while (i < ac)
	{
		tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (tab);
}

int	*ft_bubblesort_tab(int *tab, int ac)
{
	int	i;
	int	tmp;
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < ac - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
	}
	return (tab);
}

int	ft_check_rep(int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (tab[i] == tab[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_and_make(int ac, char **av, t_intl **st_a)
{
	int	i;
	int	*tab;
	int	*ordered;

	i = 1;
	while (i < ac)
	{
		if (!ft_check_valid(av[i++]))
			return (0);
	}
	tab = ft_tab_create(ac, av);
	if (!ft_check_rep(tab, ac - 1))
	{
		free(tab);
		return (0);
	}
	ordered = ft_bubblesort_tab(ft_tab_create(ac, av), ac - 1);
	if (!ft_stacker(st_a, ac - 1, tab, ordered))
		return (0);
	return (1);
}
