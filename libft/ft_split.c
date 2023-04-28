/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:06:59 by jaejkim           #+#    #+#             */
/*   Updated: 2023/01/29 18:10:17 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_scount(char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = -1;
	count = 0;
	flag = 0;
	while (s[++i])
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
	}
	return (count);
}

static int	ft_slen(char *s, char c, int s_idx)
{
	int	temp;

	temp = s_idx;
	while (s[s_idx])
	{
		if (s[s_idx] == c)
			return (s_idx - temp);
		s_idx++;
	}
	return (s_idx - temp);
}

static void	*ft_freemalloc(char **result, int r_idx)
{
	while (r_idx + 1)
	{
		free(result[r_idx]);
		r_idx--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		s_idx;
	int		r_idx;
	int		length;

	result = (char **)ft_calloc((ft_scount((char *)s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	s_idx = 0;
	r_idx = -1;
	while (++r_idx < ft_scount((char *)s, c) && s[s_idx])
	{
		while (s[s_idx] == c)
			s_idx++;
		length = ft_slen((char *)s, c, s_idx);
		result[r_idx] = ft_substr((char *)s, s_idx, length);
		if (!result[r_idx])
			return (ft_freemalloc(result, r_idx));
		s_idx += length;
	}
	return (result);
}
