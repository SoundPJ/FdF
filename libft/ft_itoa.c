/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:19:51 by pjerddee          #+#    #+#             */
/*   Updated: 2022/03/07 02:44:49 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	strrev(unsigned char *s);
static char	*zeromax(int n, char *a);
static char	*nummalloc(int n);

char	*ft_itoa(int n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = nummalloc(n);
	if (!a)
		return (0);
	if (n == 0 || n == -2147483648)
		return (zeromax(n, a));
	if (n < 0)
	{
		a[i++] = '-';
		n = -1 * n;
	}
	while (n > 0)
	{
		a[i++] = (char)((n % 10) + '0');
		n = n / 10;
	}
	a[i] = 0;
	strrev((unsigned char *)(a + (a[0] == '-')));
	return (a);
}

static void	strrev(unsigned char *s)
{
	size_t			i;
	size_t			len;
	unsigned char	temp;

	i = 0;
	len = ft_strlen((char *)s);
	while (i < (len / 2))
	{
		temp = s[i];
		s[i] = s[len - i -1];
		s[len - 1 - i++] = temp;
	}
}

static char	*zeromax(int n, char *a)
{
	if (!n)
		ft_strlcpy(a, "0", 2);
	else
		ft_strlcpy(a, "-2147483648", 12);
	return (a);
}

static char	*nummalloc(int n)
{
	int		digit;
	char	*a;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n = n / 10;
		digit++;
	}
	digit++;
	a = (char *)malloc(digit * sizeof(char));
	return (a);
}
