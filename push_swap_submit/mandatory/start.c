/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:55:53 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/16 20:38:16 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushswap_start(t_node *a, t_node *b, t_info *info)
{
	if (check_duplication(a) == -42)
	{
		ft_lstclear(&a);
		print_error(-42);
	}
	if (check_sort(a) == 1)
	{
		ft_lstclear(&a);
		exit(1);
	}
	get_chunk(&a, &b, info);
}
