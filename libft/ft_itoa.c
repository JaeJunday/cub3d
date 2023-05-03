/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:17:56 by jaejkim           #+#    #+#             */
/*   Updated: 2023/05/03 21:18:04 by jaejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaejkim <jaejkim@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/19 19:29:35 by jaejkim		   #+#	#+#			 */
/*   Updated: 2022/11/19 21:13:38 by jaejkim		  ###   ########.fr	   */
/*																			*/
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
