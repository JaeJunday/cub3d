/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:06:59 by jaejkim           #+#    #+#             */
/*   Updated: 2022/11/20 01:42:36 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
