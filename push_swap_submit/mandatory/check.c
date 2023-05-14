/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:52:33 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/12 19:55:40 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplication(t_node *a)
{
	t_node	*cur;
	t_node	*tmp;

	cur = a;
	while (cur)
	{
		tmp = cur->next;
		while (tmp)
		{
			if (cur->value == tmp->value)
				return (-42);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	check_sort(t_node *a)
{
	int	flag;

	flag = 1;
	while (a && a->next)
	{
		if (a->value > a->next->value)
		{
			flag = 0;
			break ;
		}
		a = a->next;
	}
	return (flag);
}
