/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
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
/*   ft_lstlast_bonus.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaejkim <jaejkim@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/14 10:05:45 by jaejkim		   #+#	#+#			 */
/*   Updated: 2022/11/19 23:11:15 by jaejkim		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
