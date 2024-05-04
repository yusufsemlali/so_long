/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:59:05 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/04 18:39:09 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_static_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		if (i == 0 || i == game->rows || j == 0 || j == game->cols)
			put_img(game, game->walls[2], j * 64, i * 64);
		else
			put_img(game, game->walls[5], j * 64, i * 64);
	}
	else if (game->map[i][j] == 'E')
		put_img(game, game->exit, j * 64, i * 64);
	else if (game->map[i][j] == '0')
		put_img(game, game->floor, j * 64, i * 64);
}

void	place_dynamic_elements(t_game *game, int i, int j, int *c_count)
{
	if (game->map[i][j] == 'C')
	{
		put_img(game, game->collectable[*c_count % 7], j * 64, i * 64);
		(*c_count)++;
	}
	else if (game->map[i][j] == 'P')
		put_img(game, game->player_idle, j * 64, i * 64);
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
