/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdeci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:56:02 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/16 12:04:57 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	itoa_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = itoa_len(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	else if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

char	*ft_unsignitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	nb;

	nb = n;
	len = itoa_len(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

int	ft_putdeci(int str)
{
	char	*deci;
	int		deci_len;

	deci = ft_itoa(str);
	if (!deci)
		return (0);
	deci_len = ft_strlen(deci);
	ft_str(deci);
	free(deci);
	return (deci_len);
}

int	ft_putunsigned(unsigned int ui)
{
	char	*unsign;
	int		unsign_len;

	unsign = ft_unsignitoa(ui);
	if (!unsign)
		return (0);
	unsign_len = ft_strlen(unsign);
	ft_str(unsign);
	free(unsign);
	return (unsign_len);
}
