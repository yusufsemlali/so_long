/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:50:56 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/25 02:52:14 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include <string.h>
// # include <math.h>
// # include <time.h>
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// #include "utils/get_next_line.h"
# include "libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	char	**visited;
	char	*line;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		p_count;
	int		e_count;
	int		c_count;
	int		i;
	int		x;
	void	*player;
	void	*collectable[7];
	void	*exit;
	void	*floor;
	void	*walls[6];
}			t_game;

void		map_open(char *file, t_game *game);
void		ft_error(t_game *game, char *msg);
void		count_characters(char *map, t_game *game);
void		map_path_check(t_game *game);
int			ft_strall(char *str, char c);
void		load_images(t_game *game);

#endif
