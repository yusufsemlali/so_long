/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:14:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/06 15:37:51 by ysemlali         ###   ########.fr       */
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
	mlx_destroy_image(game->mlx, game->player_r[0]);
	mlx_destroy_image(game->mlx, game->player_r[1]);
	mlx_destroy_image(game->mlx, game->player_r[2]);
	mlx_destroy_image(game->mlx, game->player_r[3]);
	mlx_destroy_image(game->mlx, game->player_r[4]);
	mlx_destroy_image(game->mlx, game->player_r[5]);
	mlx_destroy_image(game->mlx, game->player_r[6]);
	mlx_destroy_image(game->mlx, game->player_r[7]);
	mlx_destroy_image(game->mlx, game->player[0]);
	mlx_destroy_image(game->mlx, game->player[1]);
	mlx_destroy_image(game->mlx, game->player[2]);
	mlx_destroy_image(game->mlx, game->player[3]);
	mlx_destroy_image(game->mlx, game->player[4]);
	mlx_destroy_image(game->mlx, game->player[5]);
	mlx_destroy_image(game->mlx, game->player[6]);
	mlx_destroy_image(game->mlx, game->player[7]);
}

void	free_assets(t_game *game)
{
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->collectable[0]);
	mlx_destroy_image(game->mlx, game->collectable[1]);
	mlx_destroy_image(game->mlx, game->collectable[2]);
	mlx_destroy_image(game->mlx, game->collectable[3]);
	mlx_destroy_image(game->mlx, game->collectable[4]);
	mlx_destroy_image(game->mlx, game->collectable[5]);
	mlx_destroy_image(game->mlx, game->collectable[6]);
	mlx_destroy_image(game->mlx, game->walls[0]);
	mlx_destroy_image(game->mlx, game->walls[1]);
	mlx_destroy_image(game->mlx, game->walls[2]);
	mlx_destroy_image(game->mlx, game->walls[3]);
	mlx_destroy_image(game->mlx, game->walls[4]);
	mlx_destroy_image(game->mlx, game->walls[5]);
	free_player_assets(game);
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
	if (game->line)
		free(game->line);
	if (game->images_loaded == 1)
		free_assets(game);
	free(game);
	exit(0);
}
