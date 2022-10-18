/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:31:59 by pjerddee          #+#    #+#             */
/*   Updated: 2022/03/07 02:17:42 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*cur;
	t_list	*new_lst;

	new_lst = NULL;
	cur = lst;
	if (lst == NULL)
		return (NULL);
	while (cur != NULL)
	{
		ptr = ft_lstnew(f(cur->content));
		if (!ptr)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, ptr);
		cur = cur->next;
	}
	return (new_lst);
}
