/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:08:11 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/19 03:04:53 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_map
{
	int	p_count;
	int	c_count;
	int	e_count;
	int	l_count;
	int	l_len;
}		t_map;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ln_exists(char *buf);
size_t	ln_index(char *buf);
char	*ft_strjoin(char *line, char *buf);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strspn(const char *s, const char c);
int		ft_strrchr(const char *s, const char c);
void	count_characters(char *map, t_map *map_info);

#endif