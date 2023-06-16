/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:40:19 by diego             #+#    #+#             */
/*   Updated: 2023/06/06 15:59:18 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_intl	*st_a;
	t_intl	*st_b;

	if (ac < 3)
		return (0);
	else if (!ft_check_and_make(ac, av, &st_a))
		ft_error_msg();
	st_b = NULL;
	ft_algorithm_selector(&st_a, &st_b, ac - 1);
	intlist_clear(&st_a);
	return (1);
}
