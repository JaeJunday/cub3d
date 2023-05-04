/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:42:44 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 11:47:36 by hujeong          ###   ########.fr       */
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
