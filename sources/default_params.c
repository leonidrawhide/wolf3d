/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:45:47 by khelen            #+#    #+#             */
/*   Updated: 2020/09/08 12:52:27 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Задаем дефолтные параметры для клавиш.
*/

void	default_key_status(t_wolf *data)
{
	data->keyboard.map_status = 1; // потом поставить 0 чтобы игра не начиналась с карты
	data->keyboard.vision = 90;
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
	data->ppos.pangle = 0;
	data->ppos.pdx = cos(data->ppos.pangle) * 5;
	data->ppos.pdy = sin(data->ppos.pangle) * 5;
	data->ray_count = 0;
	if (!(data->ray = (t_ray*)malloc(sizeof(t_ray) + FOV)))
	{
		free(data->ray);
		ft_putstr("Error! Memory for ray was not allocated.\n");
		exit(0);
	}
}