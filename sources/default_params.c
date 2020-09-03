/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:45:47 by khelen            #+#    #+#             */
/*   Updated: 2020/09/03 18:15:21 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Задаем дефолтные параметры.
*/

void	default_params(t_wolf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "WOLF3D");
	data->bpp = 32;
	data->endian = 1;
	data->size_l = WIDTH * 4;
	data->min = HEIGHT > WIDTH ? WIDTH : HEIGHT;
	data->ppos.px = data->min / 2;
	data->ppos.py = data->min / 2;
}