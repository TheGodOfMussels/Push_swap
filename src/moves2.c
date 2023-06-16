/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:33:53 by dimolin2          #+#    #+#             */
/*   Updated: 2023/05/27 14:52:48 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_intl **stack_a, t_intl **stack_b)
{
	t_intl	*last;
	t_intl	*tmp;

	last = (*stack_a);
	tmp = (*stack_a);
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = (*stack_a);
	(*stack_a) = last;
	tmp->next = NULL;
	do_rrr2(stack_b);
}

void	do_rrr2(t_intl **stack_b)
{
	t_intl	*last;
	t_intl	*tmp;

	last = (*stack_b);
	tmp = (*stack_b);
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = (*stack_b);
	(*stack_b) = last;
	tmp->next = NULL;
	ft_printf("rrr\n");
}

void	do_s(t_intl **stack, char swap)
{
	int	tmp;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
	if (swap == 'a')
		ft_printf("sa\n");
	else if (swap == 'b')
		ft_printf("sb\n");
}

void	do_ss(t_intl **stack_a, t_intl **stack_b)
{
	int	tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = tmp;
	}
	ft_printf("ss\n");
}
