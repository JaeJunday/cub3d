#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list **tail, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		*tail = new;
		return ;
	}
	(*tail)->next = new;
}
