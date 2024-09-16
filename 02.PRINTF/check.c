/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:29:50 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/21 21:23:35 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putdeci(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
		return (ft_putmemo(va_arg(ap, size_t)));
	else if (c == 'x')
		return (ft_lowhex(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_uphex(va_arg(ap, unsigned int)));
	return (0);
}
