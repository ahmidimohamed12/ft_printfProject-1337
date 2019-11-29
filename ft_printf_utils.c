#include "ft_printf.h"



int	ft_strcmp(const char *s1,const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned int) s1[i] - (unsigned int)s2[i]);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar((n % 10 + '0'));
	}
	else
	{
		ft_putchar((n + '0'));
	}
}
void	ft_putnbr(int a)
{
	ft_putnbr_fd(a, 1);
}

void    ft_putchar(char c)
{
    write(1,&c,1);
}

void    ft_putstr(char *s )
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }
}
