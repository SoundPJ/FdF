/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:17:18 by pjerddee          #+#    #+#             */
/*   Updated: 2022/03/07 02:42:20 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		putpos(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char	*num;

	num = "0123456789";
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n = n * -1;
		}
		if (n < 10)
			write(fd, num + (n % 10), 1);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			write(fd, num + (n % 10), 1);
		}
	}
}
