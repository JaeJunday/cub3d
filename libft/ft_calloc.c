/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:41:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 11:41:23 by hujeong          ###   ########.fr       */
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
