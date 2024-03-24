/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:48:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/24 06:31:40 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <mlx.h>

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

	(void)ac;
	game = calloc(1, sizeof(t_game));
	map_open(av[1], game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920, 1080, "so_long");
	load_images(game);
	mlx_loop(game->mlx);
}
