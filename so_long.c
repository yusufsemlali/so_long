/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:48:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/25 01:03:53 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <mlx.h>
#define TILE_SIZE 64

void	ft_error(t_game *game, char *msg)
{
	int	i;

	i = 0;
	printf("Error\n");
	printf("%s\n", msg);
	while (game->map[i] != NULL)
		free(game->map[i++]);
	free(game->map);
	free(game);
	exit(1);
}

int	main(int ac, char **av)
{
    t_game	*game;
    int		window_width;
    int		window_height;

    (void)ac;
    game = calloc(1, sizeof(t_game));
    map_open(av[1], game);
    game->mlx = mlx_init();
    window_width = game->cols * TILE_SIZE;
    window_height = (game->rows + 1) * TILE_SIZE; // Add an extra tile's worth of height
    game->window = mlx_new_window(game->mlx, window_width, window_height, "so_long");
    load_images(game);
    mlx_loop(game->mlx);
}
