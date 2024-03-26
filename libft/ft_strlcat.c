/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:24:35 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/20 15:30:48 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	p;
	size_t	d_len;

	i = 0;
	if (!dest && size == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dest);
	if (size <= d_len)
		return (size + ft_strlen(src));
	p = size - d_len - 1;
	while (src[i] != '\0' && i < p)
	{
		dest[i + d_len] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + ft_strlen(src));
}
