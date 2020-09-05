/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:51:23 by khelen            #+#    #+#             */
/*   Updated: 2020/09/05 15:58:57 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	printvision(t_wolf *data)
{
	//int		hipotenuza;
	int		x;
	int		y;
	/*int		x1;
	int		y1;*/

	
	//data->img_d[(int)(data->ppos.pxvision * WIDTH + data->ppos.pyvision)] = 0x00FF00;
	x = data->ppos.pxvision + data->ppos.px;
	y = data->ppos.pyvision + data->ppos.py;
	while (x != data->ppos.px || y != data->ppos.py)
	{
		data->img_d[(int)(x * WIDTH + y)] = 0x00FF00;
		if (x > data->ppos.px)
			x--;
		else if (x < data->ppos.px)
			x++;
		if (y > data->ppos.py)
			y--;
		else if (y < data->ppos.py)
			y++;
	}
}

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
		if (data->x > data->ppos.px - 12 && data->x < data->ppos.px + 12
			&& data->y > data->ppos.py - 12 && data->y > data->ppos.py + 12)
		{
			printplayer(data);
			printvision(data);
		}
		printvision(data);
	}
}