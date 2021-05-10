/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:49:45 by khelen            #+#    #+#             */
/*   Updated: 2020/11/13 18:18:24 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		collision_chkr(int px, int py, t_wolf *data)
{
	int x;
	int y;

	x = (int)(px) / data->map.block;
	y = (int)(py) / data->map.block;
	data->ppos.mpp = y * data->map.width + x;
	if ((data->ppos.mpp > 0 && data->ppos.mpp < data->map.width *
	data->map.height && data->map.z_matrix[y][x] == 1) ||
	(x <= 0 || y <= 0) || (x >= data->map.width || y >= data->map.height))
		return (0);
	else
		return (1);
}

int		collision_up(t_wolf *data, int i)
{
	if (collision_chkr(data->ppos.px + data->ppos.pdx + i, data->ppos.py,
	data) == 0)
		return (0);
	if (collision_chkr(data->ppos.px, data->ppos.py + data->ppos.pdy + i,
	data) == 0)
		return (0);
	if (collision_chkr(data->ppos.px + data->ppos.pdx + i, data->ppos.py +
	data->ppos.pdy + i, data) == 0)
		return (0);
	return (1);
}

int		collision_down(t_wolf *data, int i)
{
	if (collision_chkr(data->ppos.px - data->ppos.pdx + i, data->ppos.py,
	data) == 0)
		return (0);
	else if (collision_chkr(data->ppos.px, data->ppos.py - data->ppos.pdy + i,
	data) == 0)
		return (0);
	if (collision_chkr(data->ppos.px - data->ppos.pdx + i, data->ppos.py -
	data->ppos.pdy + i, data) == 0)
		return (0);
	return (1);
}

int		collision(int key, t_wolf *data)
{
	if (key == ARROW_UP)
	{
		if (collision_up(data, 0) == 0)
			return (0);
		if (collision_up(data, 5) == 0)
			return (0);
		if (collision_up(data, -5) == 0)
			return (0);
	}
	if (key == ARROW_DOWN)
	{
		if (collision_down(data, 0) == 0)
			return (0);
		if (collision_down(data, 5) == 0)
			return (0);
		if (collision_down(data, -5) == 0)
			return (0);
	}
	return (1);
}

int		do_key(int key, void *param)
{
	t_wolf *data;

	data = (t_wolf *)param;
	key2(key, data);
	if ((collision(key, data) == 1))
		key1(key, data);
	if (key == M_KEY)
		data->keyboard.map_status = data->keyboard.map_status == 0 ? 1 : 0;
	if (key == SPACE)
		key3(data);
	if (key == W_KEY && data->ppos.head_pos < 90)
		data->ppos.head_pos += 5;
	if (key == S_KEY && data->ppos.head_pos > -90)
		data->ppos.head_pos -= 5;
	if (key == ESC)
		red_button(data);
	param = data;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_thread_wolf(data);
	return (0);
}
