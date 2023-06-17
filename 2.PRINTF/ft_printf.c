/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:12:11 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/15 20:13:40 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		str_len;

	va_start(ap, str);
	str_len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str_len += check(ap, *str);
		}
		else
		{
			ft_putchar(*str);
			str_len++;
		}
		str++;
	}
	va_end(ap);
	return (str_len);
}
