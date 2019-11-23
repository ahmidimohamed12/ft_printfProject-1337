#include "ft_printf.h"


int ft_strlen(int a)
{
    int i;
    i = 0;
    while (a[i] != '\0')
        i++;
    return (i);
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
