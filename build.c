#include "../so_long.h"

void	place_static_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		if (i == 0 || i == game->rows || j == 0 || j == game->cols)
			put_img(game, game->walls[2], j * game->t_s, i * game->t_s);
		else
			put_img(game, game->walls[5], j * game->t_s, i * game->t_s);
	}
	else if (game->map[i][j] == 'E')
		put_img(game, game->exit, j * game->t_s, i * game->t_s);
	else if (game->map[i][j] == '0')
		put_img(game, game->floor, j * game->t_s, i * game->t_s);
}

void	place_dynamic_elements(t_game *game, int i, int j, int *c_count)
{
	if (game->map[i][j] == 'C')
	{
		put_img(game, game->collectable[*c_count % 7], j * game->t_s, i
			* game->t_s);
		(*c_count)++;
	}
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player_idle, j
			* game->t_s, i * game->t_s);
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
