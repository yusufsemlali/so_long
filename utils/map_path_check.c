/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:07:45 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/24 03:34:06 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "get_next_line.h"

void	free_visited_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->visited[i] != NULL)
	{
		free(game->visited[i]);
		i++;
	}
	free(game->visited);
}

void	floodfill(t_game *game, int row, int col)
{
	if (row < 0 || col < 0 || row >= game->rows || col >= game->cols
		|| game->visited[row][col] == '1' || game->map[row][col] == '1')
		return ;
	game->visited[row][col] = '1';
	floodfill(game, row + 1, col);
	floodfill(game, row - 1, col);
	floodfill(game, row, col + 1);
	floodfill(game, row, col - 1);
}

void	validate_path(t_game *game)
{
	int	i;
	int	x;

	floodfill(game, game->player_y, game->player_x);
	i = 0;
	while (game->map[i] != NULL)
	{
		x = 0;
		while (game->map[i][x] != '\0')
		{
			if (game->map[i][x] == 'C' && game->visited[i][x] != '1')
				ft_error(game, "Collectible is not reachable");
			if (game->map[i][x] == 'E' && game->visited[i][x] != '1')
				ft_error(game, "Exit is not reachable");
			x++;
		}
		i++;
	}
}

void	map_path_check(t_game *game)
{
	game->i = 0;
	game->x = 0;
	while (game->map[game->i] != NULL)
	{
		if (ft_strchr(game->map[game->i], 'P') != NULL)
		{
			game->player_x = ft_strchr(game->map[game->i], 'P')
				- game->map[game->i];
			game->player_y = game->i;
		}
		game->i++;
	}
	game->visited = ft_split(game->line, '\n');
	game->i = 0;
	while (game->visited[game->i] != NULL)
	{
		game->x = 0;
		while (game->visited[game->i][game->x] != '\0')
			game->visited[game->i][game->x++] = '0';
		game->i++;
	}
	validate_path(game);
	free_visited_map(game);
}
