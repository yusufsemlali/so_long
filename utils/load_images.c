/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:51:05 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/24 03:51:53 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "get_next_line.h"
#include "../libft/libft.h"

void	load_images(t_game *game)
{
    game->player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm",
            &game->player_width, &game->player_height);
    game->collectible = mlx_xpm_file_to_image(game->mlx, "images/collectible.xpm",
            &game->collectible_width, &game->collectible_height);
    game->exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm",
            &game->exit_width, &game->exit_height);
    game->floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm",
            &game->floor_width, &game->floor_height);
    game->wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm",
            &game->wall_width, &game->wall_height);
}
