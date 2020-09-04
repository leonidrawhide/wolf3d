/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:08:27 by khelen            #+#    #+#             */
/*   Updated: 2020/09/04 17:07:13 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Рисуем карту
*/

void	printlab(t_wolf *data)
{
	int w;
	int h;

	w = data->x / BLOCK;
	h = data->y / BLOCK;
	if (w < data->map.height && h < data->map.width)
	{
		if (data->map.z_matrix[w][h] == 1 && data->y < data->map.new_width &&
			data->x < data->map.new_height)
			data->img_d[data->x * WIDTH + data->y] = 0xFF0000;
		else if (data->map.z_matrix[w][h] == 0 && data->y < data->map.new_width &&
			data->x < data->map.new_height)
			data->img_d[data->x * WIDTH + data->y] = 0x9E0202;
	}
}

/*
** Рисуем квадратик для модельки игрока
*/

void	printplayer(t_wolf *data)
{
	int x;
	int y;

	x = data->ppos.px - 10;
	y = data->ppos.py - 10;
	while (y < (data->ppos.py + 10))
	{
		data->img_d[x * WIDTH + y] = data->color;
		x++;
		if (x == (data->ppos.px + 10))
		{
			x = data->ppos.px - 10;
			y++;
		}
	}
}

/*
** Рисуем игрока на карте и саму карту соответственно
*/

void	printmap(t_wolf *data)
{
	if (data->keyboard.map_status == 1)
	{
		printlab(data);
		if (data->x == data->ppos.px && data->y == data->ppos.py)
			printplayer(data);
	}
}

/*
** Рисуем картинку на выбранной линии (потоке)
*/

void	*print_wolf(void *data)
{
	t_wolf *newdata;

	newdata = (t_wolf *)data;
	while (newdata->y < WIDTH)
	{
		printmap(data);
		newdata->y++;
	}
	newdata->y = 0;
	data = newdata;
	return (0);
}

/*
** Распределение линий по потокам, кол-во которых равно высоте окна.
*/

int		print_thread_wolf(t_wolf *data)
{
	pthread_t	thread_id;

	data->y = 0;
	data->x = 0;
	data->color = 0xFFFFFF;
	while (data->x < HEIGHT)
	{
		pthread_create(&thread_id, NULL, print_wolf, (void *)data);
    	pthread_join(thread_id, NULL);
		thread_id++;
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	return (0);
}