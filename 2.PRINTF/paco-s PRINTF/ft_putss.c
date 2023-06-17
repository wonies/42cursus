/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:11:42 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/21 21:21:55 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfs.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	char	*nullcheck;

	nullcheck = "(null)";
	if (str == NULL)
	{
		if( ft_str(nullcheck) == -1)
			return -1;
		else
			return (ft_strlen(nullcheck));
	}
	if(ft_str(str) == -1)
		return (-1);
	return (ft_strlen(str));
}

int	ft_str(char *s)
{
	if (!s)
		return -1;
	if (write(1, s, ft_strlen(s)) < 0)
		return -1;
	return (0);
}
