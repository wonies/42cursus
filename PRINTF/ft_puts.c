/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:11:42 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/15 21:23:30 by wonhshin         ###   ########.fr       */
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
	int		i;
	char	*nullcheck;

	nullcheck = "(null)";
	if (str == NULL)
	{
		ft_str(nullcheck);
		return (ft_strlen(nullcheck));
	}
	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
	return (i);
}

void	ft_str(char *s)
{
	write(1, s, ft_strlen(s));
}
