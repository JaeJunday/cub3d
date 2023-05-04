/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:42:53 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 11:47:40 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;
	size_t	src_len;
	size_t	des_len;

	des_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = des_len;
	j = 0;
	while (src[j] && (des_len + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (des_len < dstsize)
		return (des_len + src_len);
	else
		return (dstsize + src_len);
}
