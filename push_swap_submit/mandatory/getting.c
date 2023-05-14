/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:56:40 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/14 21:56:33 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_chunk(t_node **a, t_info *info)
{
	int		size;
	int		chunk;

	chunk = 0;
	size = ft_lstsize(*a);
	info->size = size;
	if (size <= 5)
		return (-114);
	else if (size <= 100)
		chunk = 15;
	else
		chunk = 30;
	info->chunk = chunk;
	return (chunk);
}

void	get_chunk(t_node **a, t_node **b, t_info *info)
{
	int		chunk;
	int		size;

	size = ft_lstsize(*a);
	chunk = create_chunk(a, info);
	get_order(a, info);
	if (chunk == -114)
		handmade_count(a, b, size);
	else
	{
		put_sort(a, b, size, chunk);
		sort_b(a, b, size);
	}
}

void	get_order(t_node **a, t_info *info)
{
	int		rank;
	long	min;
	t_node	*temp;

	rank = 1;
	while (rank <= info->size)
	{
		min = 2147483648;
		temp = *a;
		while (temp)
		{
			if (min > temp->value && (temp->order == 0))
				min = temp->value;
			temp = temp->next;
		}
		temp = *a;
		while (temp)
		{
			if (temp->value == min)
				temp->order = rank++;
			temp = temp->next;
		}
	}
}
