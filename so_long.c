/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:48:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/06 16:18:00 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_game *game, char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
	close_game(game);
}

int	key_press_event(int keycode, t_game *game)

{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->is_moving = 1;
		movement(game, game->player_x, game->player_y - 1);
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->is_moving = 1;
		movement(game, game->player_x - 1, game->player_y);
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->is_moving = 1;
		movement(game, game->player_x, game->player_y + 1);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->is_moving = 1;
		movement(game, game->player_x + 1, game->player_y);
	}
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}

int	key_release_event(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP || keycode == KEY_A
		|| keycode == KEY_LEFT || keycode == KEY_S || keycode == KEY_DOWN
		|| keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->is_moving = 0;
	}
	return (0);
}

int	idle_animation(t_game *game)
{
	int	player_x;
	int	player_y;

	if (game->is_moving == 0)
	{
		player_x = game->player_x * 64;
		player_y = game->player_y * 64;
		put_img(game, game->floor, player_x, player_y);
		put_img(game, game->player_idle[game->frame], player_x, player_y);
		game->frame_counter++;
		if (game->frame_counter >= FRAME_DELAY)
		{
			game->frame++;
			if (game->frame >= 8)
				game->frame = 0;
			game->frame_counter = 0;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		ft_error(NULL, "Invalid number of arguments");
	game = ft_calloc(1, sizeof(t_game));
	map_open(av[1], game);
	game->mlx = mlx_init();
	game->w = (game->cols + 1) * 64;
	game->h = (game->rows + 1) * 64;
	game->window = mlx_new_window(game->mlx, game->w, game->h, "so_long");
	load_images(game);
	mlx_hook(game->window, 2, 1L << 0, key_press_event, game);
	mlx_hook(game->window, 3, 1L << 1, key_release_event, game);
	mlx_loop_hook(game->mlx, idle_animation, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
