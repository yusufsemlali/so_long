/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:10:57 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/25 10:11:47 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "get_next_line.h"

void	place_static_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		if (i == 0 || i == game->rows - 1 || j == 0 || j == game->cols - 1)
			mlx_put_image_to_window(game->mlx, game->window, game->walls[2], j
				* 64, i * 64);
		else
			mlx_put_image_to_window(game->mlx, game->window, game->walls[5], j
				* 64, i * 64);
	}
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, j * 64, i
			* 64);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor, j * 64, i
			* 64);
}

void	place_dynamic_elements(t_game *game, int i, int j, int *c_count)
{
	if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectable[*c_count % 7], j * 64, i * 64);
		(*c_count)++;
	}
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player, j * 64, i
			* 64);
}

void	place_elements(t_game *game)
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

void	load_walls(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	game->walls[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_1.xpm", &x, &y);
	game->walls[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_2.xpm", &x, &y);
	game->walls[2] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_3.xpm", &x, &y);
	game->walls[3] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_4.xpm", &x, &y);
	game->walls[4] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_5.xpm", &x, &y);
	game->walls[5] = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall/wall_6.xpm", &x, &y);
	while (i < 6)
	{
		if (!game->walls[i])
			ft_error(game, "Wall image not found");
		i++;
	}
}

void	load_collectables(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	game->collectable[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_1.xpm", &x, &y);
	game->collectable[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_2.xpm", &x, &y);
	game->collectable[2] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_3.xpm", &x, &y);
	game->collectable[3] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_4.xpm", &x, &y);
	game->collectable[4] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_5.xpm", &x, &y);
	game->collectable[5] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_6.xpm", &x, &y);
	game->collectable[6] = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectables/collectable_7.xpm", &x, &y);
	while (i < 7)
	{
		if (!game->collectable[i])
			ft_error(game, "Collectable image not found");
		i++;
	}
}

void	load_images(t_game *game)
{
	int	x;
	int	y;

	game->floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor/floor_2.xpm",
			&x, &y);
	if (!game->floor)
		ft_error(game, "Floor image not found");
	game->exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit/door_1.xpm",
			&x, &y);
	if (!game->exit)
		ft_error(game, "Exit image not found");
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/idle_1.xpm", &x, &y);
	if (!game->player)
		ft_error(game, "Player image not found");
	load_walls(game);
	load_collectables(game);
	place_elements(game);
}
