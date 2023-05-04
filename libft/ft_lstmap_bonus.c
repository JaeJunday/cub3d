/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:42:15 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 11:47:25 by hujeong          ###   ########.fr       */
/*                                                                            */
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
