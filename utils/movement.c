/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:40:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/25 10:37:59 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_window(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x * 64, y * 64);
}

void	print_number_of_moves(t_game *game, char pos)
{
	if (pos == 'C' || (pos == 'E' && game->c_count == 0) || pos == '0')
		game->moves++;
	printf("Number of moves: %d\n", game->moves);
}

void	movement(t_game *game, int x, int y)
{
	char	pos;

	game->x = game->player_x + x;
	game->y = game->player_y + y;
	pos = game->map[game->y][game->x];
	if (pos == '1' || (pos == 'E' && game->c_count != 0))
		return ;
	if (pos == 'C')
	{
		game->c_count--;
		game->map[game->y][game->x] = '0';
		update_window(game, game->floor, game->x, game->y);
		update_window(game, game->player, game->x, game->y);
	}
	if (pos == 'E' && game->c_count == 0)
	{
		printf("You win!\n");
		close_game(game);
	}
	update_window(game, game->floor, game->player_x, game->player_y);
	game->player_x = game->x;
	game->player_y = game->y;
	update_window(game, game->player, game->player_x, game->player_y);
	print_number_of_moves(game, pos);
}
