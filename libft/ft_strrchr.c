/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:07:03 by jaejkim           #+#    #+#             */
/*   Updated: 2022/11/20 01:43:52 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[len - i] == uc || uc == '\0')
			return ((char *)s + len - i);
		i++;
	}
	return (0);
}
