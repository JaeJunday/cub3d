#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (0);
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
