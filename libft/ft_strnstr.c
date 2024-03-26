/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:24:44 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/19 17:17:07 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t	n_len;

	if (*n == '\0')
		return ((char *)h);
	n_len = ft_strlen(n);
	while (*h && l >= n_len)
	{
		if (*h == *n && ft_strncmp(h, n, n_len) == 0)
			return ((char *)h);
		h++;
		l--;
	}
	return (NULL);
}
