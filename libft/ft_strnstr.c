/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:36:15 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/23 00:41:25 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] != 0 && len-- > 0)
	{
		if (little[0] == big[i++])
		{
			j = 0;
			while (little[j] != 0 && len + 1 >= ft_strlen(little))
			{
				if (little[j] != big[i - 1 + j])
					break ;
				j++;
			}
			if (little[j] == 0)
				return ((char *)big + i - 1);
		}
	}
	return (NULL);
}
