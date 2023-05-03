#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	uc = c;
	i = 0;
	while (s[i] || uc == '\0')
	{
		if (s[i] == uc)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
