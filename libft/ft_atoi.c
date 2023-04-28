/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:01:34 by jaejkim           #+#    #+#             */
/*   Updated: 2023/04/22 23:10:10 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static	int	ft_check_overflow(const char *str, int sign, long num, int i)
{
	long	before;
	long	after;

	before = num * sign;
	after = (num * 10 + (*(str + i) - '0')) * sign;
	if (sign == 1 && (before > 0 && after < 0))
		return ((int)LONG_MAX);
	else if (sign == -1 && (before < 0 && after > 0))
		return ((int)LONG_MIN);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		check;
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = ft_check_overflow(str, sign, num, i);
		if (check != 1)
			return (check);
		num = num * 10 + (str[i] - '0');
		++i;
	}
	return (num * sign);
}
