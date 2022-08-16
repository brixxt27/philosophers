#include "../inc/philosophers.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	size *= count;
	while (size--)
		((char *)ptr)[size] = 0;
	return (ptr);
}

static int	ft_size_nb(int n)
{
	int	i;

	i = 1 + !(n) + (n < 0);
	while (n && i++)
		n /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				i;
	unsigned int	u;

	i = ft_size_nb(n);
	res = (char *)ft_calloc(i, 1);
	if (!res)
		return (NULL);
	res[0] = '-';
	res[--i] = '\0';
	u = -n * (n < 0) + n * !(n < 0);
	if (!u)
		res[i - 1] = '0';
	while (u)
	{
		res[--i] = (u % 10) + '0';
		u /= 10;
	}
	return (res);
}
