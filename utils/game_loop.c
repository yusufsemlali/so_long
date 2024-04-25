/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:16:31 by ysemlali          #+#    #+#             */
/*   Updated: 2024/04/25 15:46:25 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_input(t_game *game)
{
	if (game->move == KEY_UP)
		movement(game, game->player_x - 1, game->player_y);
	if (game->move == KEY_DOWN)
		movement(game, game->player_x + 1, game->player_y);
	if (game->move == KEY_LEFT)
		movement(game, game->player_x, game->player_y - 1);
	if (game->move == KEY_RIGHT)
		movement(game, game->player_x, game->player_y + 1);
}
void	render_game(t_game *game)
{
	// change the player pose to idle after a sertain amount of time
	mlx_put_image_to_window(game->mlx, game->window, game->player_idle,
		game->player_x * 64, game->player_y * 64);
}

int	game_loop(t_game *game)
{
	if (game->is_running == 1)
	{
		handle_input(game);
		render_game(game);
	}
	return (0);
}
