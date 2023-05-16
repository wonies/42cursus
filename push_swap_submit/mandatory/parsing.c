/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:07:34 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/16 16:01:20 by wonhshin         ###   ########.fr       */
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
		if (!res)
			return (NULL);
		j = 0;
		while (res[j] != 0)
		{
			if (res[j][0] == '\0')
			{
				ft_lstclear(a);
				free(res[j]);
				print_error(-42);
			}
			ft_lstadd_back(a, ft_atoi(res[j]));
			if (ft_atoi(res[j]) == 110401080911)
			{
				ft_lstclear(a);
				free(res[j]);
				print_error(-42);
			}
			free(res[j]);
			j++;
		}
		free(res);
		i++;
	}
	return (res);
}

