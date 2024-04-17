/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:40:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/04/16 21:31:34 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	get_direction(int old_x, int old_y, int new_x, int new_y)
{
	int	dx;
	int	dy;

	dx = new_x - old_x;
	dy = new_y - old_y;
	if (dx > 0)
		return (FORWARD);
	else if (dx < 0)
		return (REVERSE);
	else if (dy > 0)
		return (FORWARD);
	else if (dy < 0)
		return (REVERSE);
	return (FORWARD);
}

void	animate_player(t_game *game, int x, int y)
{
	int	direction;
	int	i;

	i = 0;
	// Update the window with the floor image at the player's old position
	update_window(game, game->floor, game->player_x, game->player_y);
	// Calculate the direction of the player's movement
	direction = get_direction(game->player_x, game->player_y, x, y);
	// Animate the player
	while (i < 8)
	{
		if (direction == FORWARD)
			update_window(game, game->player[i], x, y);
		else if (direction == REVERSE)
			update_window(game, game->player_r[i], x, y);
		usleep(20000);
		i++;
	}
	// Update the window with the player's idle image at the new position
	update_window(game, game->player_idle, x, y);
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
	}
	if (pos == 'E' && game->c_count == 0)
	{
		printf("You win!\n");
		close_game(game);
	}
	// Animate the player
	// animate_player(game, x, y);
	
	// Update the map with the new player position
	game->map[game->player_y][game->player_x] = '0'; // Clear the old position
	game->player_x = game->x;
	game->player_y = game->y;
	game->map[game->player_y][game->player_x] = 'P'; // Set the new position
	// Display the new player position
	update_window(game, game->player_idle, game->player_x, game->player_y);
	// Display the floor at the old player position
	update_window(game, game->floor, game->x, game->y);
	print_number_of_moves(game, pos);
}
