/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:51:23 by khelen            #+#    #+#             */
/*   Updated: 2020/09/07 16:02:50 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

float	mod(float i)
{
	return ((i < 0) ? -i : i);
}

float	max1(float a, float b)
{
	return (a > b ? a : b);
}

void	draw_line(float x1, float y1, t_wolf *data)
{
	float	max;
	float	x_step;
	float	y_step;
	float	x0;
	float	y0;
	t_ray	*temp;

	x0 = data->ppos.px;
	y0 = data->ppos.py;
	x_step = x1 - x0;
	y_step = y1 - y0;
	max = max1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	data->hipo = 0;
	temp = data->ray;
	while (((int)(x1 - x0) != 0 || (int)(y1 - y0) != 0) /*&& (data->ray_count < FOV - 1)*/)
	{
		if (data->img_d[(int)x1 * WIDTH + (int)y1] != 0xFF0000 && data->img_d[(int)x1 * WIDTH + (int)y1] != 0x000000)
			data->img_d[(int)x1 * WIDTH + (int)y1] = 0x00FF00;
		if (data->img_d[(int)x1 * WIDTH + (int)y1] == 0xFF0000)
			data->hipo = sqrt(pow((int)(x1 - x0), 2) + pow((int)(x1 - x0), 2));
		if (x1 < x0)
			x1 += mod(x_step);
		else if (x1 > x0)
			x1 -= x_step;
		if (y1 < y0)
			y1 += mod(y_step);
		else if (y1 > y0)
			y1 -= y_step;
		if (((int)(x1 - x0) == 0 || (int)(y1 - y0) == 0) && (data->ray_count < FOV - 2))
		{
			data->ray_count++;
			/*data->ray->dist = data->hipo;
			data->ray = data->ray->next;*/
			/*data->ppos.pangle -= 0.1;
			if (data->ppos.pangle < 0)
				data->ppos.pangle += 2 * PI;
			data->ppos.pdx = cos(data->ppos.pangle) * 5;
			data->ppos.pdy = sin(data->ppos.pangle) * 5;
			x1 = data->ppos.px + data->ppos.pdx * 50;
			y1 = data->ppos.py + data->ppos.pdy * 50;*/
		}
	}
	//data->ray = temp;
}

void	printvision(t_wolf *data)
{
	float	x;
	float	y;

	x = data->ppos.px + data->ppos.pdx * 50;
	y = data->ppos.py + data->ppos.pdy * 50;
	
	draw_line(x, y, data);
}

void	printlab(t_wolf *data)
{
	int w;
	int h;

	w = data->x / BLOCK;
	h = data->y / BLOCK;
	if (w < data->map.height && h < data->map.width)
	{
		if (data->map.z_matrix[w][h] == 1 && data->y < data->map.new_width &&
			data->x < data->map.new_height && ((data->x % BLOCK != 0) && (data->y % BLOCK != 0)))
			data->img_d[data->x * WIDTH + data->y] = 0xFF0000;
		else if (data->y < data->map.new_width &&
			data->x < data->map.new_height && data->map.z_matrix[w][h] == 0 && 
			(data->x % BLOCK != 0) && (data->y % BLOCK != 0))
			data->img_d[data->x * WIDTH + data->y] = 0x9E0202;
		else if (data->y < data->map.new_width &&
			data->x < data->map.new_height &&
			((data->x % BLOCK == 0) || (data->y % BLOCK == 0)))
			data->img_d[data->x * WIDTH + data->y] = 0x000000;
	}
}

/*
** Рисуем кружок для модельки игрока
*/

void	printplayer(t_wolf *data)
{
	int x;
	int y;

	x = data->ppos.px - 12;
	y = data->ppos.py - 12;
	while (y < (data->ppos.py + 12))
	{
		if (sqrt(pow(data->ppos.px - x, 2) + pow(data->ppos.py - y, 2)) < 12)
			data->img_d[x * WIDTH + y] = data->color;
		x++;
		if (x == (data->ppos.px + 12))
		{
			x = data->ppos.px - 12;
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
		/*if (data->x > data->ppos.px - 12 && data->x < data->ppos.px + 12
			&& data->y > data->ppos.py - 12 && data->y > data->ppos.py + 12)	// круг игрока диаметр радиус 12
		{
			printplayer(data);
			printvision(data);
		}*/
		if (data->x == data->ppos.px && data->y == data->ppos.py)	// рисуем один пиксель игрока
			data->img_d[data->x * WIDTH + data->y] = data->color;
		printvision(data);
	}
}