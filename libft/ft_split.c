/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:46:29 by pjerddee          #+#    #+#             */
/*   Updated: 2022/08/08 12:23:18 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		word_count(char const *s, char c, int *n);
static char	**strmalloc(char const *s, int *n);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		*n;
	size_t	len;

	len = ft_strlen(s);
	n = (int *)malloc((len + 2) * sizeof(int));
	if (!n)
		return (0);
	ft_bzero(n, (len + 2) * sizeof(int));
	word_count(s, c, n);
	arr = strmalloc(s, n);
	free (n);
	return (arr);
}

void	word_count(char const *s, char c, int *n)
{
	int	i;
	int	j;
	int	match;

	i = 0;
	j = 0;
	match = (s[i] != c);
	while (s[i++])
	{
		if (s[i - 1] == c)
		{
			if (match == 0 && i != 1)
				n[j++] = i - 1;
			match = 1;
		}
		else
		{
			if (match == 1)
				n[j++] = i - 1;
			match = 0;
		}
	}
	if (j % 2 != 0)
		n[j++] = ft_strlen(s);
	n[j] = -1;
}

static char	**strmalloc(char const *s, int *n)
{
	int		i;
	int		len;
	char	**a;

	i = -1;
	len = 0;
	while (n[len++] >= 0)
		;
	a = (char **)malloc(sizeof(char *) * (((len - 1) / 2) + 1));
	if (!a)
		return (0);
	while (++i < (len - 1) / 2)
	{
		a[i] = (char *)malloc(sizeof(char) * (1 + n[(2 * i) + 1] - n[2 * i]));
		if (!a[i])
		{
			while (--i >= 0)
				free(a[i]);
			free(a);
			return (0);
		}
		ft_strlcpy(a[i], s + n[2 * i], 1 + n[(2 * i) + 1] - n[2 * i]);
	}
	a[i] = NULL;
	return (a);
}
