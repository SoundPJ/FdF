/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:31:39 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/24 20:45:23 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr != 0)
	{
		while (i < len)
		{
			ptr[i] = s[i];
			i++;
		}
		ptr[i] = 0;
		return (ptr);
	}
	else
		return (0);
}
