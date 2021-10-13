#include "libft.h"

static int	ft_isws(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

long	ft_atol(const char *str)
{
	int				sign;
	long			res;
	unsigned int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isws(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}
