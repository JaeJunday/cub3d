#include "libft.h"

char	*ft_strnstr(const char *dest, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char *)dest);
	i = 0;
	while (dest[i] && i < len)
	{
		j = 0;
		while (dest[i + j] == to_find[j] && i + j < len && dest[i])
		{
			j++;
			if (!to_find[j])
				return ((char *)dest + i);
		}
		i++;
	}
	return (0);
}
