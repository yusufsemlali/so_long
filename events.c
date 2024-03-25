/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:40:44 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/25 08:10:00 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press_event(int keycode, t_game *game)
{
    if (game->key_is_pressed == keycode)
    {
        game->key_is_pressed = 0;
        printf("key released\n");
    }
    
    if (game->key_is_pressed == 0)
    {
        game->key_is_pressed = keycode;
        printf("key pressed\n");
    }
    return (0); 
}
