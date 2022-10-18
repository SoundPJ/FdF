/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:23:22 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/20 22:37:22 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (size + src_len);
	while (src[i] != 0 && (dst_len + i) < size - 1 && size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
