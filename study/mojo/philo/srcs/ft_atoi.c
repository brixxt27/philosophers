#include <limits.h>
#include "../inc/philosophers.h"

int	ft_atoi(const char *str)
{
	int				ng;
	unsigned long	n;

	n = 0;
	ng = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		ng = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		n = n * 10 + (*str - '0');
		str++;
		if (n > LONG_MAX)
		{
			if (ng > 0)
				return (-1);
			return (0);
		}
	}
	return (n * ng);
}
