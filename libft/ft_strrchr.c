/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:05:35 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/23 00:54:48 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_len;
	char	*ptr;

	c = (unsigned char)c;
	ptr = (char *)s;
	s_len = ft_strlen(ptr);
	if (c == '\0')
		return (ptr + s_len);
	while (s_len >= 0)
	{
		if (ptr[s_len] == c)
			return (ptr + s_len);
		s_len--;
	}
	return (NULL);
}
