/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:44:46 by diego             #+#    #+#             */
/*   Updated: 2023/05/31 00:39:11 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_tab_attach_two(int *tab, int second, int first, int sector)
{
	int	*new_tab;
	int	i;

	if (!(sector))
		new_tab = (int *)malloc(sizeof(int) * 2);
	else
		new_tab = (int *)malloc(sizeof(int) * (sector + 2));
	if (!new_tab)
		return (0);
	i = 0;
	while (i < sector)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = first;
	i++;
	new_tab[i] = second;
	free(tab);
	return (new_tab);
}

int	intlist_is_under(t_intl **list, int value)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (tmp->content <= value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	intlist_is_over(t_intl **list, int value)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (tmp->content > value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_error_msg(void)
{
	ft_printf("Error\n");
	exit(0);
}
