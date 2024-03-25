/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:40:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/25 08:00:14 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *game, int x, int y)
{
	int new_x;
	int new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
    printf("movement\n");
    printf("game->player_x: %d\n", game->player_x);
	// if (game->map[new_y][new_x] == '1')
	// 	return ;
	// if (game->map[new_y][new_x] == 'E' && game->c_count == 0)
	// 	close_game(game);
	// if (game->map[new_y][new_x] == 'C')
	// {
	// 	game->c_count--;
	// 	// refresh_map(game);
	// }
	// mlx_put_image_to_window(game->mlx, game->window, game->floor, game->player_x
	// 	* 64, game->player_y * 64);
	// mlx_put_image_to_window(game->mlx, game->window, game->player, new_x * 64,
	// 	new_y * 64);
	// game->player_x = new_x;
	// game->player_y = new_y;
}

