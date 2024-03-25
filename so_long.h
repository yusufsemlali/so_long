/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:50:56 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/25 08:00:35 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include <string.h>
// # include <math.h>
// # include <time.h>
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

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
	void	*player;
	void	*collectable[7];
	void	*exit;
	void	*floor;
	void	*walls[6];
	int		w;
	int		h;
	int		i;
	int		x;
	int		key_is_pressed;
	void	*close_game;
}			t_game;

void		map_open(char *file, t_game *game);
void		ft_error(t_game *game, char *msg);
void		count_characters(char *map, t_game *game);
void		map_path_check(t_game *game);
int			ft_strall(char *str, char c);
void		load_images(t_game *game);
void		movement(t_game *game, int x, int y);
int			close_game(t_game *game);
void		game_update(t_game *game);
int			key_press_event(int keycode, t_game *game);
int			key_release_event(int keycode, t_game *game);

#endif
