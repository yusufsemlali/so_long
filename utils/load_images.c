/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:51:05 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/24 06:50:18 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "get_next_line.h"
void *create_sub_image(t_game *game, void *src_img, int width, int height)
{
    void *sub_img;
    int *src_data;
    int *sub_data;
    int bpp, sl, endian;

    // Create a new image of the required size
    sub_img = mlx_new_image(game->mlx, width, height);

    // Get the data addresses of the source and new images
    src_data = (int *)mlx_get_data_addr(src_img, &bpp, &sl, &endian);
    sub_data = (int *)mlx_get_data_addr(sub_img, &bpp, &sl, &endian);

    // Copy the pixel data from the source image to the new image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            sub_data[y * width + x] = src_data[y * width + x];
        }
    }

    return sub_img;
}

void place_walls(t_game *game)
{
    int x, y;

    for (y = 0; y < game->rows; y++)
    {
        for (x = 0; x < game->cols; x++)
        {
            if (game->map[y][x] == '0')
            {
                // void *tile = create_sub_image(game, game->floor, 64, 64);
               mlx_put_image_to_window(game->mlx, game->window,
                    game->floor, x * 64, y * 64);
                // mlx_destroy_image(game->mlx, tile);  // Free the tile image
            }
        }
    }
}

void	load_images(t_game *game)
{
	int	x;
	int	y;

	game->floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor2.xpm", &x, &y);
	if (!game->floor)
		ft_error(game, "floor image not found");
        place_walls(game);
	// game->player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm",
	// 		&game->player_width, &game->player_height);
	// game->collectible = mlx_xpm_file_to_image(game->mlx,
	// 		"images/collectible.xpm", &game->collectible_width,
	// 		&game->collectible_height);
	// game->exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm",
	// 		&game->exit_width, &game->exit_height);
	// game->floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm",
	// 		&game->floor_width, &game->floor_height);
}
