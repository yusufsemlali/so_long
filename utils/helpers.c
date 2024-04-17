/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:23:03 by ysemlali          #+#    #+#             */
/*   Updated: 2024/04/17 16:51:01 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_window(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x * 64, y * 64);
}

void	print_number_of_moves(t_game *game, char pos)
{
	if (pos == 'C' || (pos == 'E' && game->c_count == 0) || pos == '0')
		game->moves++;
	printf("Number of moves: %d\n", game->moves);
}

void	*get_img(t_game *game, char *filepath, int *x, int *y)
{
	return (mlx_xpm_file_to_image(game->mlx, filepath, x, y));
}

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

void	check_images(t_game *game, void **images, int num, char *message)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (!images[i])
			ft_error(game, message);
		i++;
	}
}
