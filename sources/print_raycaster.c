/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_raycaster.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:55:56 by khelen            #+#    #+#             */
/*   Updated: 2020/09/14 19:30:59 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	print3d(t_wolf *data)
{
	//int		matrix[HEIGHT][WIDTH];

	/*int x = 0;
	int y = 0;*/
	int counter = 0;
	data->ray.length = WIDTH / FOV;
	if (data->dist[data->y / data->ray.length] != 0 && data->dist[data->y / data->ray.length] != -1)
	{
		if (data->x > (data->dist[data->y / data->ray.length]) && data->x > (data->dist[data->y / data->ray.length]))
			data->img_d[data->x * WIDTH + data->y] = 0x00FF00 - data->dist[data->y / data->ray.length] * 100;
		else
			data->img_d[data->x * WIDTH + data->y] = 0x0000FF;
	}
	else
		data->img_d[data->x * WIDTH + data->y] = 0x0000FF;
	if ((data->y % data->ray.length == 0) && data->y != 0)
		counter++;
	/*int n = 0;
	int i = 0;
	data->ray.num = WIDTH / FOV;
	if (data->dist[i] != 0)
	{
		data->img_d[data->x * WIDTH + data->y] = 0x00FF00;
	}
	n++;
	if (n > data->ray.num)
	{
		i++;
		data->ray.num += data->ray.num;
	}*/
	/*int n = 0;
	int	distant = 0;
	data->ray.num = WIDTH / FOV;
	while (data->dist[n] != -1)
	{
		while (data->dist[data->y / data->ray.num])
		data->img_d[data->x * WIDTH + data->y] = 0x00FF00;
	}*/
}

void	print_raycaster(void *data)
{
	t_wolf *newdata;

	newdata = (t_wolf *)data;
	while (newdata->y < WIDTH)
	{
		print3d(data);
		newdata->y++;
	}
	newdata->y = 0;
	data = newdata;
}