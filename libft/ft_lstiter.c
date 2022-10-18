/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:13:17 by pjerddee          #+#    #+#             */
/*   Updated: 2022/03/07 01:28:04 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (lst == NULL)
		return ;
	ptr = lst;
	while (ptr != NULL)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
