/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:50:46 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/26 16:21:23 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s) - 1)
		ptr = (char *)malloc((1) * sizeof(char));
	else if (start + len > ft_strlen(s))
		ptr = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (start <= ft_strlen(s) - 1)
	{
		while (len-- > 0 && s[start + i] != 0)
		{
			ptr[i] = s[start + i];
			i++;
		}
	}
	ptr[i] = 0;
	return (ptr);
}
