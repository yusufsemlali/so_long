/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:51:05 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/25 03:33:18 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "get_next_line.h"

#define TILE_SIZE 64

void	place_walls(t_game *game)
{
	int i, j;
	for (i = 0; i <= game->rows; i++)
	{
		for (j = 0; j <= game->cols; j++)
		{
			if (game->map[i][j] == '1')
			{
				// Use wall_4 for the border
				if (i == 0 || i == game->rows - 1 || j == 0 || j == game->cols
					- 1)
				{
					mlx_put_image_to_window(game->mlx, game->window,
						game->walls[2], j * TILE_SIZE, i * TILE_SIZE);
				}
				// Use wall_2 for the inner walls
				else
				{
					mlx_put_image_to_window(game->mlx, game->window,
						game->walls[5], j * TILE_SIZE, i * TILE_SIZE);
				}
			}
		}
	}
}

void	place_floors(t_game *game)
{
	int i, j;
	for (i = 0; i <= game->rows; i++)
	{
		for (j = 0; j <= game->cols; j++)
		{
			if (game->map[i][j] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->floor, j
					* TILE_SIZE, i * TILE_SIZE);
			}
		}
	}
}
void	place_exit(t_game *game)
{
	int i, j;
	for (i = 0; i <= game->rows; i++)
	{
		for (j = 0; j <= game->cols; j++)
		{
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->exit, j
					* TILE_SIZE, i * TILE_SIZE);
			}
		}
	}
}

void place_player(t_game *game)
{
    int i, j;
    for (i = 0; i <= game->rows; i++) 
    {
        for (j = 0; j <= game->cols; j++) 
        {
            if (game->map[i][j] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->player, j * TILE_SIZE, i * TILE_SIZE); 
            }
        }
    }
}

void place_collectables(t_game *game)
{
    int i, j;
    int collectable_count = 0;
    for (i = 0; i <= game->rows; i++) 
    {
        for (j = 0; j <= game->cols; j++) 
        {
            if (game->map[i][j] == 'C')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->collectable[collectable_count % 7], j * TILE_SIZE, i * TILE_SIZE); 
                collectable_count++;
            }
        }
    }
}

void load_images(t_game *game)
{
    char *wall_files[6] = {"./assets/wall/wall_1.xpm",
            "./assets/wall/wall_2.xpm", "./assets/wall/wall_3.xpm",
            "./assets/wall/wall_4.xpm", "./assets/wall/wall_5.xpm",
            "./assets/wall/wall_6.xpm"};
    char *floor_file = "./assets/floor/floor_1.xpm";
    char *exit_file = "./assets/exit/door_1.xpm";
    char *player_file = "./assets/player/idle_1.xpm";
    char *collectable_files[7] = {"./assets/collectables/collectable_1.xpm",
            "./assets/collectables/collectable_2.xpm", "./assets/collectables/collectable_3.xpm",
            "./assets/collectables/collectable_4.xpm", "./assets/collectables/collectable_5.xpm",
            "./assets/collectables/collectable_6.xpm", "./assets/collectables/collectable_7.xpm"};

    int x, y;
    // Load all wall images
    for (int i = 0; i < 6; i++)
    {
        game->walls[i] = mlx_xpm_file_to_image(game->mlx, wall_files[i], &x, &y);
        if (!game->walls[i])
            ft_error(game, "Wall image not found");
    }

    // Load floor image
    game->floor = mlx_xpm_file_to_image(game->mlx, floor_file, &x, &y);
    if (!game->floor)
        ft_error(game, "Floor image not found");

    // Load exit image
    game->exit = mlx_xpm_file_to_image(game->mlx, exit_file, &x, &y);
    if (!game->exit)
        ft_error(game, "Exit image not found");

    // Load player image
    game->player = mlx_xpm_file_to_image(game->mlx, player_file, &x, &y);
    if (!game->player)
        ft_error(game, "Player image not found");

    // Load collectable images
    for (int i = 0; i < 7; i++)
    {
        game->collectable[i] = mlx_xpm_file_to_image(game->mlx, collectable_files[i], &x, &y);
        if (!game->collectable[i])
		{
			printf("Collectable %d image not found\n", i);
            ft_error(game, "Collectable image not found");
		}
    }

    place_walls(game);
    // place_floors(game);
    place_exit(game);
    place_player(game);
    place_collectables(game);
}
