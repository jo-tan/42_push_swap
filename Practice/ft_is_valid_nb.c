#include <stdio.h>

int	ft_is_valid_nb(const char *nptr)
{
	if (!nptr || *nptr == '\0')
		return (0);
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr != '\0')
	{
		if (*nptr < '0' || *nptr > '9')
			return (0);
		nptr++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i = 1;

	if (ac <= 1)
		return (0);
	else
	{
		while (--ac > 0)
		{
			if (ft_is_valid_nb(av[i]))
				printf("%s is valid\n", av[i]);
			else if (!ft_is_valid_nb(av[i]))
				printf("%s NOT valid\n", av[i]);
			i++;
		}
	}
}

/* 
./test 1 0 -2 +3 --2 one hello
1 is valid
0 is valid
-2 is valid
+3 is valid
--2 NOT valid
one NOT valid
hello NOT valid

./test "" "1" "0" "010" "2100000" "-222222" | cat -e
 NOT valid$
1 is valid$
0 is valid$
010 is valid$
2100000 is valid$
-222222 is valid$

*/
