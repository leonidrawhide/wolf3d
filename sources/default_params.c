/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:45:47 by khelen            #+#    #+#             */
/*   Updated: 2020/11/13 17:04:32 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	default_key_status(t_wolf *data)
{
	data->keyboard.map_status = 1;
	data->keyboard.vision = 90;
}

void	default_params1(t_wolf *data)
{
	default_key_status(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "WOLF3D");
	data->map.new_width = ((int)min1(WIDTH, HEIGHT) / data->map.width)
	* data->map.width;
	data->map.new_height = ((int)min1(WIDTH, HEIGHT) / data->map.height)
	* data->map.height;
	data->map.block = (int)min1(WIDTH, HEIGHT) / (int)max1(data->map.width,
	data->map.height);
	data->kef = max1(data->map.width, data->map.height) / 3;
	data->ppos.px = (data->map.width / 2) * data->map.block +
	0.5 * data->map.block;
	data->ppos.py = (data->map.height / 2) * data->map.block +
	0.5 * data->map.block;
	if (data->map.z_matrix[(int)(data->ppos.py / data->map.block)]
	[(int)(data->ppos.px / data->map.block)] != 0)
		error_and_free("Error. Illegal map! Central square must be free.\n",
		data);
	data->ppos.pa = PI2;
	default_params2(data);
}

void	default_params2(t_wolf *data)
{
	if (data->ppos.pa > 2 * PI)
		data->ppos.pa -= 2 * PI;
	if (data->ppos.pa < 0)
		data->ppos.pa += 2 * PI;
	data->ppos.pdx = cos(data->ppos.pa) * 2;
	data->ppos.pdy = sin(data->ppos.pa) * 2;
	data->count = 0;
	data->keyboard.mx = WIDTH / 2;
	data->keyboard.my = HEIGHT / 2;
	data->ppos.head_pos = 0;
}
