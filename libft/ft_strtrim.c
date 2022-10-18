/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:13:06 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/26 17:36:25 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	char	*head;

	i = 0;
	end = ft_strlen(s1);
	while (i < end)
	{
		if (ft_strchr(set, (int)s1[i]))
			i++;
		else
			break ;
	}
	while (end > i)
	{
		if (ft_strchr(set, (int)s1[end - 1]))
			end--;
		else
			break ;
	}
	head = (char *)malloc(sizeof(char) * (end - i + 1));
	if (!head)
		return (0);
	ft_strlcpy(head, s1 + i, end - i + 1);
	return (head);
}
