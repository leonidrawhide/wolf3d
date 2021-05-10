/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:52:27 by apidgeot          #+#    #+#             */
/*   Updated: 2020/11/10 19:52:43 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		deal_key(int key, t_wolf *data)
{
	do_key(key, data);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_thread_wolf(data);
	return (0);
}

int		mouse_hook(int mousecode, int x, int y, t_wolf *data)
{
	y = x;
	if (mousecode == 5)
		data->y = 1;
	x = y;
	print_thread_wolf(data);
	return (0);
}

int		mouse_motion(int x, int y, t_wolf *data)
{
	if (x < data->keyboard.mx)
		data->ppos.pa -= 0.1;
	else if (x > data->keyboard.mx)
		data->ppos.pa += 0.1;
	data->keyboard.mx = x;
	if (data->ppos.pa > 2 * PI)
		data->ppos.pa -= 2 * PI;
	else if (data->ppos.pa < 0)
		data->ppos.pa += 2 * PI;
	data->ppos.pdx = cos(data->ppos.pa) * 5;
	data->ppos.pdy = sin(data->ppos.pa) * 5;
	if (y < data->keyboard.my && data->ppos.head_pos < 90)
		data->ppos.head_pos += 5;
	else if (y > data->keyboard.my && data->ppos.head_pos > -90)
		data->ppos.head_pos -= 5;
	data->keyboard.my = y;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_thread_wolf(data);
	return (0);
}

int		undo_key(int key, void *param)
{
	t_wolf *data;

	data = (t_wolf *)param;
	param = data;
	key++;
	key--;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_thread_wolf(data);
	return (0);
}

void	hooks_and_params(t_wolf *data)
{
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), red_button, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_hook(data->win_ptr, 6, 0, mouse_motion, data);
	mlx_hook(data->win_ptr, 2, 0, do_key, data);
	mlx_hook(data->win_ptr, 3, 0, undo_key, data);
	mlx_loop(data->mlx_ptr);
}
