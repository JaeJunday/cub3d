/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
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
/*   ft_lstmap_bonus.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaejkim <jaejkim@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/14 10:06:19 by jaejkim		   #+#	#+#			 */
/*   Updated: 2022/11/23 06:46:33 by jaejkim		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*move;
	t_list	*temp;
	t_list	*head;
	void	*m_content;

	if (!lst || !f)
		return (NULL);
	move = lst;
	head = NULL;
	while (move)
	{
		m_content = f(move->content);
		temp = ft_lstnew(m_content);
		if (!temp)
		{
			del(m_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, temp);
		move = move->next;
	}
	return (head);
}
