/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 04:34:53 by pjerddee          #+#    #+#             */
/*   Updated: 2022/03/07 22:33:11 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (0);
	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dest;
	while (n-- > 0)
	{
		p_dst[i] = (unsigned char)p_src[i];
		i++;
	}
	return (dest);
}
