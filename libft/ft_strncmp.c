/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:47:57 by pjerddee          #+#    #+#             */
/*   Updated: 2022/03/08 23:12:27 by pjerddee         ###   ########.fr       */
/*   Updated: 2022/03/08 17:39:44 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ptr1[i] != 0 && ptr2[i] != 0 && n)
	{
		if (ptr1[i] > ptr2[i])
			return (1);
		else if (ptr1[i] < ptr2[i])
			return (-1);
		i++;
		n--;
	}
	if (ft_strlen((char *) ptr1) > ft_strlen((char *) ptr2) && n != 0)
		return (1);
	else if (ft_strlen((char *) ptr1) < ft_strlen((char *) ptr2) && n != 0)
		return (-1);
	else
		return (0);
}
