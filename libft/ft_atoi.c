/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:38:54 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/24 16:29:47 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(char c);
static int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	val;
	int	i;

	sign = 1;
	val = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
		sign = ft_issign(nptr[i++]);
	while (ft_isdigit(nptr[i]))
		val = (val * 10) + (nptr[i++] - 48);
	return (sign * val);
}

static int	ft_issign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' \
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
