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
