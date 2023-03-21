/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:11:42 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/16 12:15:42 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	char	*nullcheck;

	nullcheck = "(null)";
	if (str == NULL)
	{
		ft_str(nullcheck);
		return (ft_strlen(nullcheck));
	}
	ft_str(str);
	return (ft_strlen(str));
}

void	ft_str(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}
