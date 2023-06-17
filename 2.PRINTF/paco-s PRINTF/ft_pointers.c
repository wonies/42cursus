/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:56:39 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/21 21:23:16 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfs.h"

int	ft_memlen(size_t n)
{
	int	len;
	int	notation;

	len = 0;
	notation = 16;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= notation;
		len++;
	}
	return (len);
}

char	*ft_memitoa(size_t n)
{
	char	*str;
	int		len;

	if (!n)
		return (ft_strdup("0x0"));
	len = ft_memlen(n);
	len += 2;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (str);
}

size_t	ft_putmemo(size_t mem)
{
	char	*point;
	int		point_len;

	point = ft_memitoa(mem);
	if (!point)
		return (-1);
	point_len = ft_strlen(point);

	if(ft_str(point) == -1) {
		free(point);
		return (-1);
	}
	free(point);
	return (point_len);
}
