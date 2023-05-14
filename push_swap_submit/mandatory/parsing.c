/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:07:34 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/12 20:07:45 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsing(t_node **a, int ac, char **av)
{
	int		i;
	int		j;
	char	**res;

	i = 1;
	res = NULL;
	while (i < ac)
	{
		res = ft_split(av[i], ' ');
		j = 0;
		while (res[j] != 0)
		{
			if (res[j][0] == '\0')
				print_error(-42);
			ft_lstadd_back(a, ft_atoi(res[j]));
			if (ft_atoi(res[j]) == 110401080911)
				print_error(-42);
			j++;
		}
		i++;
	}
	return (res);
}
