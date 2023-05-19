/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:05:06 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/19 19:22:40 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_org(t_node **a, char *str)
{
	ft_lstclear(a);
	free(str);
	print_error(-42);
}

void	res_search(t_node **a, char **res, int j)
{
	while (res[j] != 0)
	{
		if (res[j][0] == '\0')
			error_org(a, res[j]);
		ft_lstadd_back(a, ft_atoi(res[j]));
		if (ft_atoi(res[j]) == 110401080911)
			error_org(a, res[j]);
		free(res[j]);
		j++;
	}
}

char	**parsing(t_node **a, int ac, char **av)
{
	int		i;
	char	**res;

	i = 1;
	res = NULL;
	while (i < ac)
	{
		res = ft_split(av[i], ' ');
		if (!res)
			return (NULL);
		res_search(a, res, 0);
		free(res);
		i++;
	}
	return (res);
}
