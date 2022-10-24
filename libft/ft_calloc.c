/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:00:00 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/24 15:59:59 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*p;
	size_t	m;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	m = size * nitems;
	p = (char *)malloc(m);
	if (!p)
		return (0);
	ft_bzero(p, size * nitems);
	return (p);
}
