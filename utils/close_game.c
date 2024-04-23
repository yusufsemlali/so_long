/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:14:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/04/23 21:26:19 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_player_assets(t_game *game)
{
    
}
void	free_collectibles_assets(t_game *game)
{
	int i = 0;
    while (i < 7)
    {
        if (game->collectable[i] != NULL)
            mlx_destroy_image(game->mlx, game->collectable[i]);
        i++;
    }
}
void	free_exit_wall_floor_assets(t_game *game)
{
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->walls);
	mlx_destroy_image(game->mlx, game->floor);
}
void	free_assets(t_game *game)
{
	free_player_assets(game);
	free_collectibles_assets(game);
	free_exit_wall_floor_assets(game);
}

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i] != NULL)
			free(game->map[i++]);
		free(game->map);
	}
	i = 0;
	if (game->visited)
	{
		i = 0;
		while (game->visited[i] != NULL)
			free(game->visited[i++]);
		free(game->visited);
	}
	if (game->line)
		free(game->line);
	free(game);
	system("leaks so_long");
	exit(0);
}
