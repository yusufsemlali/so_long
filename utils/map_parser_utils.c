/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:50:32 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/24 03:49:27 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "get_next_line.h"

void	count_characters(char *map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			game->p_count++;
		else if (map[i] == 'C')
			game->c_count++;
		else if (map[i] == 'E')
			game->e_count++;
		else if (map[i] != '1' && map[i] != '0')
			ft_error(game, "invalid character in map");
		i++;
	}
}

int	ft_strall(char *str, char c)
{
	while (*str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}
