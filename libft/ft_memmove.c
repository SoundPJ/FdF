/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:08:58 by pjerddee          #+#    #+#             */
/*   Updated: 2022/03/08 22:57:00 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_src;
	char	*p_dest;
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	p_src = (char *)src;
	p_dest = (char *)dest;
	if (p_dest < p_src)
	{
		while (n-- > 0)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			p_dest[n] = p_src[n];
	}
	return (p_dest);
}
