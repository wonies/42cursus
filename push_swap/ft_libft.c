
#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int			sign;
	long			res;
	size_t		i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
    if (res * sign > 2147483647 || res * sign < -2147483648)
        return 110401080911;
	return (sign * res);
}

