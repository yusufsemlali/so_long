/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:02:33 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/23 23:34:45 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ln_index(char *buf)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat_2(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	if (!dst && src && !dstsize)
		return (ft_strlen(src));
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize == 0 || len_d >= dstsize)
		return (dstsize + len_s);
	while (src[i] && i < (dstsize - 1 - len_d))
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

char	*ft_substr_2(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str_start;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str_start = str;
	s += start;
	while (len--)
		*str++ = *s++;
	*str = '\0';
	return (str_start);
}

char	*ft_strjoin_2(char *line, char *buf)
{
	char	*concat;

	if (!line && !buf)
		return (NULL);
	concat = (char *)malloc(ft_strlen(line) + ft_strlen(buf) + 1);
	if (!concat)
		return (NULL);
	concat[0] = '\0';
	if (line)
		ft_strlcat_2(concat, line, ft_strlen(line) + 1);
	ft_strlcat_2(concat, buf, ft_strlen(buf) + ft_strlen(line) + 1);
	if (!concat[0])
		return (free(concat), NULL);
	return (free(line), concat);
}
