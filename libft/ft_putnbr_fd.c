#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	if (fd < 0)
		return ;
	ln = (long)n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln < 10)
	{
		ft_putchar_fd(ln + '0', fd);
		return ;
	}
	ft_putnbr_fd(ln / 10, fd);
	ft_putnbr_fd(ln % 10, fd);
}
