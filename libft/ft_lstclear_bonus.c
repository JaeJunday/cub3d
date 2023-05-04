/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:42:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/05/04 11:47:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head->next;
		del(head->content);
		free(head);
		head = tmp;
	}
	*lst = NULL;
}
