/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:08:27 by khelen            #+#    #+#             */
/*   Updated: 2020/09/03 18:18:04 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Рисуем карту
*/

void	printmap(t_wolf *data)
{
	int w;
	int h;

	if (WIDTH < HEIGHT)
	{
		data->map.new_width = WIDTH / data->map.width;
		data->map.new_height = WIDTH / data->map.height;
	}
	else
	{
		data->map.new_width = HEIGHT / data->map.width;
		data->map.new_height = HEIGHT / data->map.height;
	}	
	w = data->x / data->map.new_width;
	h = data->y / data->map.new_height;
	if (data->map.z_matrix[w][h] == 1 && (data->x < data->min) && (data->y < data->min))
		data->img_d[data->x * WIDTH + data->y] = 0xFF0000;
	else
		data->img_d[data->x * WIDTH + data->y] = 0;
}

/*
** Рисуем квадратик для модельки игрока
*/

void	printplayer(t_wolf *data)
{
	int x;
	int y;

	x = data->ppos.px - 15;
	y = data->ppos.py - 15;
	while (y < data->ppos.py)
	{
		data->img_d[x * WIDTH + y] = data->color;
		x++;
		if (x == data->ppos.px)
		{
			x = data->ppos.px - 15;
			y++;
		}
	}
}

/*
** Рисуем картинку на выбранной линии (потоке) 
*/

void	*print_wolf(void *data)
{
	t_wolf *newdata;

	newdata = (t_wolf *)data;
	while (newdata->y != WIDTH)
	{
		if (newdata->x == newdata->ppos.px && newdata->y == newdata->ppos.py)
			printplayer(newdata);
		else
			printmap(newdata);
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
	while (data->x != data->min)
	{
		pthread_create(&thread_id, NULL, print_wolf, (void *)data);
    	pthread_join(thread_id, NULL);
		thread_id++;
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	return (0);
}