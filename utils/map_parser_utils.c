/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:50:32 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/19 03:06:56 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "get_next_line.h"

int	ft_strspn(const char *s, const char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_strrchr(const char *s, const char c)
{
	int	i;
	int	x;

	i = ft_strlen(s);
	x = 0;
	while (x < i)
	{
		if (s[x] != c)
			return (x);
		x++;
	}
	return (-1);
}

void	count_characters(char *map, t_map *map_info)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			map_info->p_count++;
		else if (map[i] == 'C')
			map_info->c_count++;
		else if (map[i] == 'E')
			map_info->e_count++;
		else if (map[i] != '1' && map[i] != '0')
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
}
