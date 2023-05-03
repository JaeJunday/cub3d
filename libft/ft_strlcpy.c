/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaejkim <jaejkim@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/14 10:06:59 by jaejkim		   #+#	#+#			 */
/*   Updated: 2022/11/20 01:46:56 by jaejkim		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	leng_src;

	leng_src = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (leng_src);
	i = 0;
	while (i < leng_src && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (leng_src);
}
