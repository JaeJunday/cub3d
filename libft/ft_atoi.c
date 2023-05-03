/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hujeong <hujeong@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/14 10:01:34 by jaejkim		   #+#	#+#			 */
/*   Updated: 2023/05/02 15:00:56 by hujeong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h" 

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++str;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	num = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	if (num > 255)
		return (-1);
	return (num * sign);
}
