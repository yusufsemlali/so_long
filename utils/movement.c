/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:40:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/04/19 12:51:05 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_direction(t_game *game, int x, int y)
{
	int	dx;
	int	dy;

	dx = x - game->player_x;
	dy = y - game->player_y;
	if (dx == 1)
		game->direction = FORWARD;
	if (dx == -1)
		game->direction = REVERSE;
	if (dy == 1)
		game->direction = FORWARD;
	if (dy == -1)
		game->direction = REVERSE;
}

void	animate_player(t_game *game, int new_x, int new_y)
{
	if (game->direction == FORWARD)
		mlx_put_image_to_window(game->mlx, game->window, game->player[game->frame],
			new_x * 64, new_y * 64);
	if (game->direction == REVERSE)
		mlx_put_image_to_window(game->mlx, game->window, game->player_r[game->frame],
			new_x * 64, new_y * 64);
	game->frame++;
	if (game->frame == 8)
		game->frame = 0;
}

void	render_map(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->floor, game->player_x
		* 64, game->player_y * 64);
	mlx_put_image_to_window(game->mlx, game->window, game->floor, x * 64, y
		* 64);
	animate_player(game, x, y);
}

void	print_moves(t_game *game)
{
	
	game->moves++;
	char *num = ft_strjoin("Moves: ", ft_itoa(game->moves));
	mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, num);	
}

void	movement(t_game *game, int x, int y)
{
	char	next;

	next = game->map[y][x];
	if (next == '1' || (next == 'E' && game->c_count != 0))
		return ;
	if (next == 'C')
	{
		game->c_count--;
		game->map[y][x] = '0';
	}
	if (next == 'E' && game->c_count == 0)
	{
		printf("You won!\n");
		close_game(game);
	}
	render_map(game, x, y);
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	print_moves(game);
}
