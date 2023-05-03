#include "libft.h" 

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < count)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
