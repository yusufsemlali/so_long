/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:14:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/03 20:26:47 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_player_assets(t_game *game)
{
   mlx_destroy_image(game->mlx, game->player_idle[0]);
   mlx_destroy_image(game->mlx, game->player_idle[1]);
   mlx_destroy_image(game->mlx, game->player_idle[2]);
   mlx_destroy_image(game->mlx, game->player_idle[3]);
   mlx_destroy_image(game->mlx, game->player_idle[4]);
   mlx_destroy_image(game->mlx, game->player_idle[5]);
   mlx_destroy_image(game->mlx, game->player_idle[6]);
   mlx_destroy_image(game->mlx, game->player_idle[7]);
}
void	free_collectibles_assets(t_game *game)
{
	mlx_destroy_image(game->mlx, game->collectable[0]);
	mlx_destroy_image(game->mlx, game->collectable[1]);
	mlx_destroy_image(game->mlx, game->collectable[2]);
	mlx_destroy_image(game->mlx, game->collectable[3]);
	mlx_destroy_image(game->mlx, game->collectable[4]);
	mlx_destroy_image(game->mlx, game->collectable[5]);
	mlx_destroy_image(game->mlx, game->collectable[6]);	
}
void	free_exit_wall_floor_assets(t_game *game)
{
	if (game->exit)
	mlx_destroy_image(game->mlx, game->exit);
	if (game->floor)
	mlx_destroy_image(game->mlx, game->walls[0]);
	if (game->walls[1])
	mlx_destroy_image(game->mlx, game->walls[1]);
	mlx_destroy_image(game->mlx, game->walls[2]);
	mlx_destroy_image(game->mlx, game->walls[3]);
	mlx_destroy_image(game->mlx, game->walls[4]);
	mlx_destroy_image(game->mlx, game->walls[5]);
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
	// i = 0;
	if (game->visited)
	{
	// 	while (game->visited[i] != NULL)
	// 		free(game->visited[i++]);
	// 	free(game->visited);
	printf("free visited\n");
	}
	free_assets(game);
	if (game->line)
		free(game->line);
	free(game);
	system("leaks so_long");
	exit(0);
}
