/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:23:03 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/03 20:20:30 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	ft_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
int valid_extension(char *file)
{
	int i;
	i = 0;
	while (file[i])
	{
		file[i] = ft_tolower(file[i]);
		i++;
	}
	char *ext = ft_strrchr(file, '.');
	printf("ext: %s\n", ext);
	if (ext == NULL || ft_strncmp(ext, ".ber", 4) != 0)
		return(-1);
	return(0);
}