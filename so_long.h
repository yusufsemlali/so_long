/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:50:56 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/15 20:30:41 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

typedef struct s_map
{
	int	p_count;
	int	c_count;
	int	e_count;
	int	line_count;
	int	line_length;
}		t_map;

#endif
