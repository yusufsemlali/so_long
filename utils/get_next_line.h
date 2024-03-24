/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:08:11 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/24 03:49:03 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ln_exists(char *buf);
size_t	ln_index(char *buf);
char	*ft_strjoin_2(char *line, char *buf);
size_t	ft_strlcat_2(char *dst, char *src, size_t dstsize);
char	*ft_substr_2(char *s, unsigned int start, size_t len);
int		ft_strspn(const char *s, const char c);
int		ft_strchr_2(const char *s, const char c);
int		ft_strrchr_2(const char *s, const char c);

#endif