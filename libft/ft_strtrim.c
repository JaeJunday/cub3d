#include "libft.h"

static char	ft_isset(char s, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (ft_isset(s1[start], (char *)set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_isset(s1[end], (char *)set))
		end--;
	result = ft_substr(s1, start, end - start + 1);
	return (result);
}
