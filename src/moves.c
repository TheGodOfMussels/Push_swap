/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:34:03 by dimolin2          #+#    #+#             */
/*   Updated: 2023/05/27 14:55:48 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_p(t_intl **stack, t_intl **dest, char push)
{
	t_intl	*tmp;

	tmp = (*stack);
	if ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		tmp->next = (*dest);
		(*dest) = tmp;
	}
	else
	{
		tmp->next = (*dest);
		(*dest) = tmp;
	}
	if (push == 'a')
		ft_printf("pa\n");
	else if (push == 'b')
		ft_printf("pb\n");
}

void	do_r(t_intl **stack, char rot)
{
	t_intl	*anchor;
	int		tmp;

	anchor = (*stack);
	while (anchor)
	{
		if (anchor && anchor->next)
		{
			tmp = anchor->content;
			anchor->content = anchor->next->content;
			anchor->next->content = tmp;
		}
		anchor = anchor->next;
	}
	if (rot == 'a')
		ft_printf("ra\n");
	else if (rot == 'b')
		ft_printf("rb\n");
}

void	do_rr(t_intl **stack_a, t_intl **stack_b)
{
	t_intl	*anchor;
	int		tmp;

	anchor = (*stack_a);
	while (anchor)
	{
		if (anchor && anchor->next)
		{
			tmp = anchor->content;
			anchor->content = anchor->next->content;
			anchor->next->content = tmp;
		}
		anchor = anchor->next;
	}
	do_rrb(stack_b);
}

void	do_rrb(t_intl **stack_b)
{
	t_intl	*anchor;
	int		tmp;

	anchor = (*stack_b);
	while (anchor)
	{
		if (anchor && anchor->next)
		{
			tmp = anchor->content;
			anchor->content = anchor->next->content;
			anchor->next->content = tmp;
		}
		anchor = anchor->next;
	}
	ft_printf("rr\n");
}

void	do_rrx(t_intl **stack, char rev)
{
	t_intl	*last;
	t_intl	*tmp;

	last = (*stack);
	tmp = (*stack);
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = (*stack);
	(*stack) = last;
	tmp->next = NULL;
	if (rev == 'a')
		ft_printf("rra\n");
	else if (rev == 'b')
		ft_printf("rrb\n");
}
