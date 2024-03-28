/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:40:47 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/27 03:07:21 by ysemlali         ###   ########.fr       */
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

#include <unistd.h> // Include this at the top of your file for the usleep function

void animate_player(t_game *game, int direction, int x, int y)
{
    // Choose the correct animation array based on the direction
    void **animation = direction == FORWARD ? game->player : game->player_rev;

    // Update the player's position
    game->player_x = x;
    game->player_y = y;

    // Loop through all frames
    for (int i = 0; i < 8; i++)
    {
        // Update the frame variable
        game->frame = i;

        // Update the window with the new player image, shifted by a small amount
        update_window(game, animation[game->frame], game->player_x + game->frame * 8, game->player_y + game->frame * 8);

        // Delay for 15 milliseconds to create a smoother transition between frames
        usleep(15000);
    }
}

void movement(t_game *game, int x, int y)
{
    char pos;

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
        animate_player(game, FORWARD, game->x, game->y);
    }
    if (pos == 'E' && game->c_count == 0)
    {
        printf("You win!\n");
        close_game(game);
    }
    update_window(game, game->floor, game->player_x, game->player_y);
    animate_player(game, FORWARD, game->x, game->y);
    print_number_of_moves(game, pos);
}