/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_small_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:10:57 by ysemlali          #+#    #+#             */
/*   Updated: 2024/04/17 16:24:15 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

static void	place_static_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		if (i == 0 || i == game->rows  || j == 0 || j == game->cols )
			put_img(game, game->walls[2], j * game->t_s, i * game->t_s);
		else
			put_img(game, game->walls[5], j * game->t_s, i * game->t_s);
	}
	else if (game->map[i][j] == 'E')
		put_img(game, game->exit, j * game->t_s, i * game->t_s);
	else if (game->map[i][j] == '0')
		put_img(game, game->floor, j * game->t_s, i * game->t_s);
}

static void	place_dynamic_elements(t_game *game, int i, int j, int *c_count)
{
	if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectable[*c_count % 7], j * game->t_s, i * game->t_s);
		(*c_count)++;
	}
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player, j
			* game->t_s, i * game->t_s);
}

static void	place_elements(t_game *game)
{
	int	i;
	int	j;
	int	c_count;

	c_count = 0;
	i = 0;
	while (i <= game->rows)
	{
		j = 0;
		while (j <= game->cols)
		{
			place_static_elements(game, i, j);
			place_dynamic_elements(game, i, j, &c_count);
			j++;
		}
		i++;
	}
}

static void	load_walls(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	game->walls[0] = get_img(game, "./assets/wall/wall_1_s.xpm", &x, &y);
	game->walls[1] = get_img(game, "./assets/wall/wall_2_s.xpm", &x, &y);
	game->walls[2] = get_img(game, "./assets/wall/wall_3_s.xpm", &x, &y);
	game->walls[3] = get_img(game, "./assets/wall/wall_4_s.xpm", &x, &y);
	game->walls[4] = get_img(game, "./assets/wall/wall_5_s.xpm", &x, &y);
	game->walls[5] = get_img(game, "./assets/wall/wall_6_s.xpm", &x, &y);
	while (i < 6)
	{
		if (!game->walls[i])
			ft_error(game, "Wall image not found");
		i++;
	}
}

static void	load_collectables(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	game->collectable[0] = get_img(game, "./assets/collects/c1_s.xpm", &x, &y);
	game->collectable[1] = get_img(game, "./assets/collects/c2_s.xpm", &x, &y);
	game->collectable[2] = get_img(game, "./assets/collects/c3_s.xpm", &x, &y);
	game->collectable[3] = get_img(game, "./assets/collects/c4_s.xpm", &x, &y);
	game->collectable[4] = get_img(game, "./assets/collects/c5_s.xpm", &x, &y);
	game->collectable[5] = get_img(game, "./assets/collects/c6_s.xpm", &x, &y);
	check_if_null(game->collectable);
	while (i < 7)
	{
		if (!game->collectable[i])
			ft_error(game, "Collectable image not found");
		i++;
	}
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
