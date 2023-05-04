/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:41:59 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 11:47:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(long number, int n)
{
	int	digit;

	digit = 1;
	while (number / 10)
	{
		digit++;
		number /= 10;
	}
	if (n < 0)
		digit++;
	return (digit);
}

static void	ft_fillresult(char *result, int n, int digit, long number)
{
	int	i;

	i = 0;
	while (i < digit)
	{
		result[digit - 1 - i] = (number % 10 + '0');
		number /= 10;
		i++;
	}
	if (n < 0)
	{
		result[0] = '-';
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digit;
	long	number;

	number = (long)n;
	if (n < 0)
	number *= -1;
	digit = ft_count_digit(number, n);
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (0);
	result[digit] = '\0';
	ft_fillresult(result, n, digit, number);
	return (result);
}
