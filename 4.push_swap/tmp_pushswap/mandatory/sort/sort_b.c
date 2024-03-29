/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:49:25 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/18 21:49:26 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_order(t_node **b, int size, int len)
{
	t_node	*temp;
	int		dot;

	temp = *b;
	dot = 1;
	while (temp->order != size)
	{
		dot++;
		temp = temp->next;
	}
	if (dot <= len)
		return (1104);
	return (1111);
}

void	b_order(t_node **b, int size)
{
	int	len;
	int	check;

	len = size / 2;
	if ((*b)->order == size)
		return ;
	check = find_order(b, size, len);
	while (1)
	{
		if (check == 1104)
			rb(b, 1);
		else if (check == 1111)
			rrb(b, 1);
		if ((*b)->order == size)
			break ;
	}
}

void	sort_b(t_node **a, t_node **b, int size)
{
	int	fforder;

	fforder = size;
	while (fforder != 0)
	{
		b_order(b, fforder);
		pa(a, b, 1);
		fforder--;
	}
}
