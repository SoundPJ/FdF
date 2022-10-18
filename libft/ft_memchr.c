/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 02:36:17 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/25 00:29:42 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	if (!n)
		return (0);
	while (n > 0)
	{
		if (*(ptr++) == (unsigned char)c)
			return (ptr - 1);
		n--;
	}
	return (0);
}
