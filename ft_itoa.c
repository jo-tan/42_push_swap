#include "ft_push_swap.h"

static int	ft_count_digit(long long int n)
{
	if (n < 0)
		return (1 + ft_count_digit(-n));
	if (n < 10)
		return (1);
	return (1 + ft_count_digit(n / 10));
}

char	*ft_itoa(int n)
{
	char			*res;
	int				len;
	long long int	nbr;

	nbr = n;
	len = ft_count_digit(nbr);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (nbr == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	else if (nbr < 0)
		nbr *= -1;
	res[0] = '-';
	res[len] = '\0';
	while (nbr)
	{
		res[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}