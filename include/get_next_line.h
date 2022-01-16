/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:11 by jatan             #+#    #+#             */
/*   Updated: 2021/08/08 20:38:09 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// char	*ft_strchr_2(const char *s, int c);
// char	*ft_strjoin_2(char const *s1, char const *s2);
// char	*ft_strdup(const char *s);
// int		ft_strlen_2(const char *s);
char	*get_next_line(int fd);

#endif