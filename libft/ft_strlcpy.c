/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:27:50 by pjerddee          #+#    #+#             */
/*   Updated: 2022/03/03 01:19:45 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != 0)
	{
		if (size > 0)
		{
			if (i < size - 1)
				dst[i] = src[i];
			else if (i == size - 1)
				dst[i] = 0;
		}
		i++;
	}
	if (i < size)
		dst[i] = 0;
	return (i);
}
