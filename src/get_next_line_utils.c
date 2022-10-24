/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:48:47 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/24 16:12:39 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen_nl(char *s, int sel);
char	*ft_strcpy(char *dst, char *src);

// 0 - return len of s without '\0'
// 1 - return '\n' id if exists, return -1 otherwise
int	ft_strlen_nl(char *s, int sel)
{
	int	i;

	i = 0;
	if (sel == 0)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (s[i] != 0)
		{
			if (s[i] == '\n')
				return (i);
			i++;
		}
		return (-1);
	}
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	ls1;
	size_t	ls2;

	ls1 = ft_strlen_nl(s1, 0);
	ls2 = ft_strlen_nl(s2, 0);
	i = 0;
	s = (char *)malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (i < ls1)
	{
		s[i] = s1[i];
		i++;
	}
	while (i < ls1 + ls2)
	{
		s[i] = s2[i - ls1];
		i++;
	}
	s[i] = 0;
	free(s1);
	free(s2);
	return (s);
}

// return char str of 0, size of n
// char	*ft_calloc(size_t n)
// {
// 	char	*p;
// 	size_t	i;

// 	i = 0;
// 	p = NULL;
// 	if (n == 0)
// 		return (NULL);
// 	p = (char *)malloc(sizeof(char) * n);
// 	if (!p)
// 		return (NULL);
// 	while (i < n)
// 		p[i++] = '\0';
// 	if (n == 0)
// 		p[0] = '\0';
// 	return (p);
// }
