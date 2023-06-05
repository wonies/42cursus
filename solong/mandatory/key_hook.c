#include "so_long.h"

int	ft_len(long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		cnt++;
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = (long)n;
	len = ft_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

void    key_hook(t_map *map)
{
    char    *str;

    str = ft_itoa(map->step_cnt);
    write(1, "kerbi's moving: \n", 17);
    write(1, str, ft_strlen_long(str));
    write(1, "\n", 1);
}