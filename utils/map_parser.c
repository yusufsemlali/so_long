/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:48:33 by ysemlali          #+#    #+#             */
/*   Updated: 2024/04/23 20:50:32 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "get_next_line.h"

void	map_rules(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
		count_characters(game->map[i++], game);
	if (game->p_count != 1 || game->c_count < 1 || game->e_count != 1)
		ft_error(game, "invalid map");
}

void	valid_border(t_game *game)
{
	char	**s;
	int		i;

	s = game->map;
	if (!ft_strall(s[0], '1') || !ft_strall(s[game->rows], '1'))
		ft_error(game, "map is not closed on top or bottom");
	i = 0;
	while (s[i] != NULL)
	{
		if (s[i][0] != '1' || s[i][game->cols] != '1')
			ft_error(game, "map is not closed on sides");
		i++;
	}
}

void	map_parser(t_game *game)
{
	valid_border(game);
	map_rules(game);
	map_path_check(game);
}

void	get_rows_cols(t_game *game)
{
	game->rows = 0;
	game->cols = ft_strlen(game->map[0]);
	while (game->map[game->rows] != NULL)
	{
		if (ft_strlen(game->map[game->rows]) != (size_t)game->cols)
			ft_error(game, "error in map portions");
		game->rows++;
	}
	game->rows--;
	game->cols--;
	if (game->rows < 3 || game->cols < 3)
		ft_error(game, "map is too small");
	if (game->rows > 100 || game->cols > 100)
		ft_error(game, "map is too big");
	if (game->rows > 40 || game->cols > 40)
		game->t_s = TILE_SIZE_S;
}

void	map_open(char *file, t_game *game)
{
	int		fd;
	char	*line;

	game->line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(game, "file open error");
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->line = ft_strjoin_2(game->line, line);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(game->line, '\n');
	get_rows_cols(game);
	map_parser(game);
	close(fd);
}
