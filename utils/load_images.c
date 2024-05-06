/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:10:57 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/06 20:07:09 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_walls_collectables(t_game *game)
{
	int	x;
	int	y;

	game->walls[0] = get_img(game, "./textures/wall/wall_1.xpm", &x, &y);
	game->walls[1] = get_img(game, "./textures/wall/wall_2.xpm", &x, &y);
	game->walls[2] = get_img(game, "./textures/wall/wall_3.xpm", &x, &y);
	game->walls[3] = get_img(game, "./textures/wall/wall_4.xpm", &x, &y);
	game->walls[4] = get_img(game, "./textures/wall/wall_5.xpm", &x, &y);
	game->walls[5] = get_img(game, "./textures/wall/wall_6.xpm", &x, &y);
	game->collectable[0] = get_img(game, "./textures/collects/c1.xpm", &x, &y);
	game->collectable[1] = get_img(game, "./textures/collects/c2.xpm", &x, &y);
	game->collectable[2] = get_img(game, "./textures/collects/c3.xpm", &x, &y);
	game->collectable[3] = get_img(game, "./textures/collects/c4.xpm", &x, &y);
	game->collectable[4] = get_img(game, "./textures/collects/c5.xpm", &x, &y);
	game->collectable[5] = get_img(game, "./textures/collects/c6.xpm", &x, &y);
	game->collectable[6] = get_img(game, "./textures/collects/c7.xpm", &x, &y);
	check_images(game, game->collectable, 7, "collectable image not found");
	check_images(game, game->walls, 6, "wall image not found");
}

void	load_player_rev(t_game *game)
{
	int	x;
	int	y;

	game->player_r[0] = get_img(game, "./textures/player/run/run_r1.xpm", &x, &y);
	game->player_r[1] = get_img(game, "./textures/player/run/run_r2.xpm", &x, &y);
	game->player_r[2] = get_img(game, "./textures/player/run/run_r3.xpm", &x, &y);
	game->player_r[3] = get_img(game, "./textures/player/run/run_r4.xpm", &x, &y);
	game->player_r[4] = get_img(game, "./textures/player/run/run_r5.xpm", &x, &y);
	game->player_r[5] = get_img(game, "./textures/player/run/run_r6.xpm", &x, &y);
	game->player_r[6] = get_img(game, "./textures/player/run/run_r7.xpm", &x, &y);
	game->player_r[7] = get_img(game, "./textures/player/run/run_r8.xpm", &x, &y);
	check_images(game, game->player_r, 7, "player rev image not found");
}

void	load_player(t_game *game)
{
	int	x;
	int	y;

	game->player[0] = get_img(game, "./textures/player/run/run_1.xpm", &x, &y);
	game->player[1] = get_img(game, "./textures/player/run/run_2.xpm", &x, &y);
	game->player[2] = get_img(game, "./textures/player/run/run_3.xpm", &x, &y);
	game->player[3] = get_img(game, "./textures/player/run/run_4.xpm", &x, &y);
	game->player[4] = get_img(game, "./textures/player/run/run_5.xpm", &x, &y);
	game->player[5] = get_img(game, "./textures/player/run/run_6.xpm", &x, &y);
	game->player[6] = get_img(game, "./textures/player/run/run_7.xpm", &x, &y);
	game->player[7] = get_img(game, "./textures/player/run/run_8.xpm", &x, &y);
	game->player_idle[0] = get_img(game, "./textures/player/idle_1.xpm", &x, &y);
	game->player_idle[1] = get_img(game, "./textures/player/idle_2.xpm", &x, &y);
	game->player_idle[2] = get_img(game, "./textures/player/idle_3.xpm", &x, &y);
	game->player_idle[3] = get_img(game, "./textures/player/idle_4.xpm", &x, &y);
	game->player_idle[4] = get_img(game, "./textures/player/idle_5.xpm", &x, &y);
	game->player_idle[5] = get_img(game, "./textures/player/idle_6.xpm", &x, &y);
	game->player_idle[6] = get_img(game, "./textures/player/idle_7.xpm", &x, &y);
	game->player_idle[7] = get_img(game, "./textures/player/idle_8.xpm", &x, &y);
	check_images(game, game->player, 8, "player run image not found");
	check_images(game, game->player_idle, 8, "player idle image not found");
}

void	load_images(t_game *game)
{
	int	x;
	int	y;

	game->floor = get_img(game, "./textures/floor/floor_2.xpm", &x, &y);
	check_images(game, &game->floor, 1, "floor image not found");
	game->exit = get_img(game, "./textures/exit/door_1.xpm", &x, &y);
	check_images(game, &game->exit, 1, "exit image not found");
	load_player(game);
	load_player_rev(game);
	load_walls_collectables(game);
	place_elements(game);
	game->images_loaded = 1;
}
