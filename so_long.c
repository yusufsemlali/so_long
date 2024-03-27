/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:48:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/27 00:56:57 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <mlx.h>

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
		free(game->map[i++]);
	free(game->map);
	free(game->line);
	free(game);
	exit(0);
}

void	ft_error(t_game *game, char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	close_game(game);
}

int	key_press_event(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		movement(game, 0, -1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		movement(game, -1, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		movement(game, 0, 1);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		movement(game, 1, 0);
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;
	if (ac != 2)
		return (printf("Error\nInvalid number of arguments\n"), 0);
	game = calloc(1, sizeof(t_game));
	game->tile_size = TILE_SIZE;
	printf("game->tile_size: %d\n", game->tile_size);
	map_open(av[1], game);
	game->mlx = mlx_init();
	game->w = (game->cols + 1) * TILE_SIZE;
	game->h = (game->rows + 1) * TILE_SIZE;
	printf("game->w: %d\n", game->w);
	game->window = mlx_new_window(game->mlx, game->w, game->h, "so_long");
	load_images(game);
	mlx_hook(game->window, 2, 1L << 0, key_press_event, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
