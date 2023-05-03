/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
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
/*   ft_isdigit.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaejkim <jaejkim@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/14 10:00:39 by jaejkim		   #+#	#+#			 */
/*   Updated: 2022/11/18 21:06:37 by jaejkim		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
