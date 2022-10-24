/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:19:53 by pjerddee          #+#    #+#             */
/*   Updated: 2022/10/24 16:12:01 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

// int		check_nl(char *buff);
int		ft_strlen_nl(char *s, int sel);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dst, char *src);
char	*ft_lastline(char *str);
char	*ft_read(char *str, int fd);
char	*get_line(char *s, int nl_id);
char	*get_remain(char *s, int nl_id);
char	*ft_strjoin_gnl(char *s1, char *s2);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_calloc(size_t size);

#endif
