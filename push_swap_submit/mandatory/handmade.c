/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handmade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:05:02 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/16 20:52:25 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_times(t_node **a)
{
	t_node	*temp;
	t_node	*last;

	temp = (*a)->next;
	last = ft_lstlast(*a);
	if ((*a)->order < last->order && last->order < temp->order)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (temp->order < (*a)->order && (*a)->order < last->order)
		sa(a, 1);
	else if ((*a)->order < temp->order && (*a)->order > last->order)
		rra(a, 1);
	else if ((*a)->order > last->order && temp->order < last->order)
		ra(a, 1);
	else if ((*a)->order > temp->order && temp->order > last->order)
	{
		sa(a, 1);
		rra(a, 1);
	}
}

void	five_times(t_node **a, t_node **b)
{
	three_times(a);
	pb(a, b, 1);
	three_times(a);
	pb(a, b, 1);
	three_times(a);
	if ((*b)->order < (*b)->next->order)
		sb(b, 1);
	pa(a, b, 1);
	three_times(a);
	pa(a, b, 1);
	three_times(a);
}

void	handmade_count(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sa(a, 1);
	else if (size <= 3)
		three_times(a);
	else if (size <= 5)
		five_times(a, b);
}
