/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:08:27 by khelen            #+#    #+#             */
/*   Updated: 2020/09/03 15:04:06 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

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
			newdata->img_d[newdata->x * WIDTH + newdata->y] = 0;
		else
			newdata->img_d[newdata->x * WIDTH + newdata->y] = newdata->color;
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
	while (data->x != HEIGHT)
	{
		pthread_create(&thread_id, NULL, print_wolf, (void *)data);
    	pthread_join(thread_id, NULL);
		thread_id++;
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	return (0);
}