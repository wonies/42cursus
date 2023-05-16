/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:11:23 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/16 20:50:50 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, int flag)
{
	t_node	*temp;

	if (*a && (*a)->next)
	{
		temp = (*a)->next;
		(*a)->next = temp->next;
		temp->next = *a;
		*a = temp;
	}
	// if (a == NULL || a->next == NULL)
	// 	return ;
	// if (a != NULL && a->next != NULL)
	// {
	// 	temp = a->next->value;
	// 	a->next->value = a->value;
	// 	a->value = temp;
	// 	temp_order = a->next->order;
	// 	a->next->order = a->order;
	// 	a->order = temp_order;
	// }
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int flag)
{
	t_node	*temp;

	if (*b && (*b)->next)
	{
		temp = (*b)->next;
		(*b)->next = temp->next;
		temp->next = *b;
		*b = temp;
	}
	// if (b == NULL || b->next == NULL)
	// 	return ;
	// if (b != NULL && b->next != NULL)
	// {
	// 	temp = b->next->value;
	// 	b->next->value = b->value;
	// 	b->value = temp;
	// 	temp_order = b->next->order;
	// 	b->next->order = b->order;
	// 	b->order = temp_order;
	// }
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
}

void	pa(t_node **a, t_node **b, int flag)
{
	t_node	*temp;

	temp = *b;
	if (temp == NULL)
		return ;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, int flag)
{
	t_node	*temp;

	temp = *a;
	if (temp == NULL)
		return ;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (flag == 1)
		write(1, "pb\n", 3);
}
