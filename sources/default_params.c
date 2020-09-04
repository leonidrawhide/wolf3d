/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:45:47 by khelen            #+#    #+#             */
/*   Updated: 2020/09/04 16:11:48 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Задаем дефолтные параметры для клавиш.
*/

void	default_key_status(t_wolf *data)
{
	data->keyboard.map_status = 1; // потом поставить 0 чтобы игра не начиналась с карты
}

/*
** Задаем дефолтные параметры.
*/

void	default_params(t_wolf *data)
{
	default_key_status(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "WOLF3D");
	data->bpp = 32;
	data->endian = 1;
	data->size_l = WIDTH * 4;
	data->map.new_width = BLOCK * data->map.width;
	data->map.new_height = BLOCK * data->map.height;
	data->ppos.px = data->map.new_height / 2;
	data->ppos.py = data->map.new_width / 2;
}