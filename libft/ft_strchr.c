/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:17:14 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/25 00:29:27 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	i;
	char			*ptr;

	c = (unsigned char)c;
	ptr = (char *)str;
	i = 0;
	while (ptr[i] != 0)
	{
		if (ptr[i] == c)
			return (ptr + i);
		i++;
	}
	if (!c)
		return (ptr + i);
	return (0);
}
