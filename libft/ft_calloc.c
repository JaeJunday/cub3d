/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:00:39 by jaejkim           #+#    #+#             */
/*   Updated: 2022/11/22 00:21:06 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	if (count < 0 || size < 0)
		return (NULL);
	result = (void *)malloc(size * count);
	if (!result)
		return (NULL);
	i = 0;
	while (i < count * size)
		((char *)result)[i++] = 0;
	return (result);
}
