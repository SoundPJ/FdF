/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:59:05 by pjerddee          #+#    #+#             */
/*   Updated: 2022/02/25 20:31:38 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	ls1;
	size_t	ls2;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	i = 0;
	s = (char *)malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!s)
		return (0);
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
	return (s);
}

// int	main(void)
// {
// 	// printf("%s\n", ft_strjoin("", "42"));
// 	char	*s = ft_strjoin("", "42");
// 	size_t	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%d\n", s[i]);
// 		i++;
// 	}
// 	printf("%d\n", strcmp(s,"42"));
// 	// printf("%zu\n", ft_strlen(""));;
// 	return(0);
// }
