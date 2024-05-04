/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:50:56 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/04 19:07:32 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64
# define TILE_SIZE_S 32
# define FORWARD 0
# define REVERSE 1
# define UP 2
# define DOWN 3
# define FRAME_DELAY 9

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

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
	int		moves;
	void	*player[8];
	void	*player_r[8];
	void	*player_idle[8];
	void	*collectable[7];
	void	*walls[6];
	void	*floor;
	void	*exit;
	int		w;
	int		h;
	int		i;
	int		x;
	int		y;
	int		frame;
	int		direction;
	int		last_direction;
	int		is_moving;
	int		frame_counter;
}			t_game;

void		ft_printf(char *str);
void		map_open(char *file, t_game *game);
void		ft_error(t_game *game, char *msg);
void		count_characters(char *map, t_game *game);
void		map_path_check(t_game *game);
int			ft_strall(char *str, char c);
void		load_images(t_game *game);
void		load_small_images(t_game *game);
void		movement(t_game *game, int x, int y);
int			close_game(t_game *game);
void		game_update(t_game *game);
int			key_press_event(int keycode, t_game *game);
int			key_release_event(int keycode, t_game *game);
void		*get_img(t_game *game, char *filepath, int *x, int *y);
void		put_img(t_game *game, void *img, int x, int y);
void		print_number_of_moves(t_game *game, char pos);
void		check_images(t_game *game, void **images, int num, char *message);
void		place_elements(t_game *game);
void		place_static_elements(t_game *game, int i, int j);
void		place_dynamic_elements(t_game *game, int i, int j, int *c_count);
int			valid_extension(char *file);

#endif
