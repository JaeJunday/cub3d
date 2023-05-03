/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstadd_back_bonus.c							 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hujeong <hujeong@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/14 10:00:54 by jaejkim		   #+#	#+#			 */
/*   Updated: 2023/05/02 16:26:02 by hujeong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

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
