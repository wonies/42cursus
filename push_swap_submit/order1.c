/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:11:23 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/14 18:52:20 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *a)
{
	int	temp;
	int	temp_order;

	if (a == NULL || a->next == NULL)
		return ;
	if (a != NULL && a->next != NULL)
	{
		temp = a->next->value;
		a->next->value = a->value;
		a->value = temp;
		temp_order = a->next->order;
		a->next->order = a->order;
		a->order = temp_order;
	}
	write(1, "sa\n", 3);
}

void	sb(t_node *b)
{
	int	temp;
	int	temp_order;

	if (b == NULL || b->next == NULL)
		return ;
	if (b != NULL && b->next != NULL)
	{
		temp = b->next->value;
		b->next->value = b->value;
		b->value = temp;
		temp_order = b->next->order;
		b->next->order = b->order;
		b->order = temp_order;
	}
	write(1, "sb\n", 3);
}

void	ss(t_node *a, t_node *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}
