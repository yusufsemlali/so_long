/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:48:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/15 20:31:59 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(void)
// {
// 	void			*x_p;
// 	void			*w_p;
// 	void			*img;
// 	int				width;
// 	int				height;
// 	int				bits_per_pixel;
// 	int				line_length;
// 	int				endian;
// 	unsigned char	*img_data;
// 	int i = 0;

// 	x_p = mlx_init();
// 	width = 1000;
// 	height = 1000;
// 	w_p = mlx_new_window(x_p, width, height, "100 by 100");
// 	img = mlx_new_image(x_p, width, height);
// 	img_data = (unsigned char *)mlx_get_data_addr(img, &bits_per_pixel,
// 			&line_length, &endian);
// 	while (i < width * height * (bits_per_pixel / 8))
// 	{
// 		img_data[i] = 76;      // Blue
// 		img_data[i + 1] = 116; // Green
// 		img_data[i + 2] = 101; // Red
// 	}
// 	mlx_put_image_to_window(x_p, w_p, img, 0, 0);
// 	mlx_loop(x_p);
// }
