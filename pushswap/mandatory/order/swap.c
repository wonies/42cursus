/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:36:55 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/18 21:53:11 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **a, int flag)
{
	t_node	*tmp;

	if ((*a) && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int flag)
{
	t_node	*tmp;

	if ((*b) && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
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
