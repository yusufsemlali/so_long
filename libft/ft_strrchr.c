/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:24:46 by ysemlali          #+#    #+#             */
/*   Updated: 2023/11/19 17:31:19 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	char	character;
	int		i;

	save = 0;
	i = 0;
	character = c;
	while (1)
	{
		if (s[i] == character)
			save = (char *)&s[i];
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (save);
}
