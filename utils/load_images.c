/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:10:57 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/27 03:04:12 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

void	place_static_elements(t_game *game, int i, int j)
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

void	place_dynamic_elements(t_game *game, int i, int j, int *c_count)
{
	if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectable[*c_count % 7], j * game->t_s, i * game->t_s);
		(*c_count)++;
	}
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player_idle, j * game->t_s, i
			* game->t_s);
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
void load_player_rev(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	game->player_rev[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_rev_1.xpm", &x, &y);
	game->player_rev[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_rev_2.xpm", &x, &y);
	game->player_rev[2] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_rev_3.xpm", &x, &y);
	game->player_rev[3] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_rev_4.xpm", &x, &y);
	game->player_rev[4] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_rev_5.xpm", &x, &y);
	game->player_rev[5] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_rev_6.xpm", &x, &y);
	game->player_rev[6] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_rev_7.xpm", &x, &y);
	game->player_rev[7] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_rev_8.xpm", &x, &y);
	while (i < 8)
	{
		if (!game->player_rev[i])
			ft_error(game, "player image not found");
		i++;
	}
	
}
void load_player(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	game->player[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_1.xpm", &x, &y);
	game->player[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_2.xpm", &x, &y);
	game->player[2] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_3.xpm", &x, &y);
	game->player[3] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_4.xpm", &x, &y);
	game->player[4] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_5.xpm", &x, &y);
	game->player[5] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_6.xpm", &x, &y);
	game->player[6] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_7.xpm", &x, &y);
	game->player[7] = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/run/run_8.xpm", &x, &y);
	while (i < 8)
	{
		if (!game->player[i])
		{
			printf("%d\n", i);
			ft_error(game, "player image not found");
		}
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
	game->player_idle = mlx_xpm_file_to_image(game->mlx,
			"./assets/player/idle_1.xpm", &x, &y);
	load_player(game);
	load_player_rev(game);
	load_walls(game);
	load_collectables(game);
	place_elements(game);
}
