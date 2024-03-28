/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_small_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:10:57 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/27 02:45:59 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

static void	place_static_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		if (i == 0 || i == game->rows - 1 || j == 0 || j == game->cols - 1)
			mlx_put_image_to_window(game->mlx, game->window, game->walls[2], j
				* game->t_s, i * game->t_s);
		else
			mlx_put_image_to_window(game->mlx, game->window, game->walls[5], j
				* game->t_s, i * game->t_s);
	}
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, j * game->t_s, i
			* game->t_s);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor, j * game->t_s, i
			* game->t_s);
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
		mlx_put_image_to_window(game->mlx, game->window, game->player, j * game->t_s, i
			* game->t_s);
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
	game->walls[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_1_s.xpm", &x, &y);
	game->walls[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_2_s.xpm", &x, &y);
	game->walls[2] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_3_s.xpm", &x, &y);
	game->walls[3] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_4_s.xpm", &x, &y);
	game->walls[4] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_5_s.xpm", &x, &y);
	game->walls[5] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_6_s.xpm", &x, &y);
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
	game->collectable[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_1_s.xpm", &x, &y);
	game->collectable[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_2_s.xpm", &x, &y);
	game->collectable[2] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_3_s.xpm", &x, &y);
	game->collectable[3] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_4_s.xpm", &x, &y);
	game->collectable[4] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_5_s.xpm", &x, &y);
	game->collectable[5] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_6_s.xpm", &x, &y);
	game->collectable[6] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_7_s.xpm", &x, &y);
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
	game->floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor/floor_2_s.xpm",
			&x, &y);
	if (!game->floor)
		ft_error(game, "Floor image not found");
	game->exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit/door_1_s.xpm",
			&x, &y);
	if (!game->exit)
		ft_error(game, "Exit image not found");
	game->player[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/idle_1_s.xpm", &x, &y);
	if (!game->player[0])
		ft_error(game, "Player image not found");
	load_walls(game);
	load_collectables(game);
	place_elements(game);
}
