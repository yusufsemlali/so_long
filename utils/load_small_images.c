/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_small_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:10:57 by ysemlali          #+#    #+#             */
/*   Updated: 2024/04/17 16:54:08 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

static void	load_walls(t_game *game)
{
	int	x;
	int	y;

	game->walls[0] = get_img(game, "./assets/wall/wall_1_s.xpm", &x, &y);
	game->walls[1] = get_img(game, "./assets/wall/wall_2_s.xpm", &x, &y);
	game->walls[2] = get_img(game, "./assets/wall/wall_3_s.xpm", &x, &y);
	game->walls[3] = get_img(game, "./assets/wall/wall_4_s.xpm", &x, &y);
	game->walls[4] = get_img(game, "./assets/wall/wall_5_s.xpm", &x, &y);
	game->walls[5] = get_img(game, "./assets/wall/wall_6_s.xpm", &x, &y);
	check_images(game, game->walls, 6, "wall image not found");
}

static void	load_collectables(t_game *game)
{
	int	x;
	int	y;

	game->collectable[0] = get_img(game, "./assets/collects/c1_s.xpm", &x, &y);
	game->collectable[1] = get_img(game, "./assets/collects/c2_s.xpm", &x, &y);
	game->collectable[2] = get_img(game, "./assets/collects/c3_s.xpm", &x, &y);
	game->collectable[3] = get_img(game, "./assets/collects/c4_s.xpm", &x, &y);
	game->collectable[4] = get_img(game, "./assets/collects/c5_s.xpm", &x, &y);
	game->collectable[5] = get_img(game, "./assets/collects/c6_s.xpm", &x, &y);
	check_images(game, game->collectable, 6, "collectable image not found");
}

void	load_small_images(t_game *game)
{
	int	x;
	int	y;

	game->floor = get_img(game, "./assets/floor/floor_2_s.xpm", &x, &y);
	if (!game->floor)
		ft_error(game, "Floor image not found");
	game->exit = get_img(game, "./assets/exit/door_1_s.xpm", &x, &y);
	if (!game->exit)
		ft_error(game, "Exit image not found");
	game->player[0] = get_img(game, "./assets/player/idle_1_s.xpm", &x, &y);
	if (!game->player[0])
		ft_error(game, "Player image not found");
	load_walls(game);
	load_collectables(game);
	place_elements(game);
}
