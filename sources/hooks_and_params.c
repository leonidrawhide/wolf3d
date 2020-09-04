/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:49:45 by khelen            #+#    #+#             */
/*   Updated: 2020/09/04 16:12:09 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Обрабатываем сигналы с клавиатуры.
*/

void	do_key(int key, t_wolf *data)
{
	if (key == ARROW_UP)
		data->ppos.px--;
	if (key == ARROW_DOWN)
		data->ppos.px++;
	if (key == ARROW_LEFT)
		data->ppos.py--;
	if (key == ARROW_RIGHT)
		data->ppos.py++;
	if (key == M_KEY)
		data->keyboard.map_status = data->keyboard.map_status == 0 ? 1 : 0;
	if (key == ESC)
		red_butt(data);
}

/*
** Функция для вызова сигнала с кливиатуры и перезаписи картинки после
** обработки сигнала с клавиатуры. Далее перерисовываем картинку заново.
*/

int		deal_key(int key, t_wolf *data)
{
	do_key(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_thread_wolf(data);
	return (0);
}

/*
** Функция для вызова выхода из программы.
*/

int		red_butt(t_wolf *data)
{
	free(data);
	exit(0);
}

/*
** Обрабатываем сигналы с мышки.
*/

int		mouse_hook(int mousecode, int x, int y, t_wolf *data)
{
	x = y;
	if (mousecode == 5)
		data->x = 1;
	print_thread_wolf(data);
	return (0);
}

/*int		key_release(int keycode, void *param)
{
	t_wolf *data1;

	data1 = (t_wolf *)param;
	if (keycode == 126)
		data1->ppos.px--; // up
	if (keycode == 125)
		data1->ppos.px++; // down
	if (keycode == 123)
		data1->ppos.py--; // left
	if (keycode == 124)
		data1->ppos.py++; // right
	param = data1;
	print_thread_wolf(data1);
	return (0);
}*/

/*
** Обработка долгих удерживаний с клавиатуры, необходимо для
** плавного перемещения по карте.
*/

int 	key_press(int keycode, void *param)
{
	t_wolf *data1;

	data1 = (t_wolf *)param;
	if (keycode == ARROW_UP)
		data1->ppos.px -= 5;
	if (keycode == ARROW_DOWN)
		data1->ppos.px += 5;
	if (keycode == ARROW_LEFT)
		data1->ppos.py -= 5;
	if (keycode == ARROW_RIGHT)
		data1->ppos.py += 5;
	param = data1;
	print_thread_wolf(data1);
	return (0);
}

/*
** Раскидаем сигналы мышки и клавиш по функциям.
*/

void	hooks_and_params(t_wolf *data)
{
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), red_butt, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_hook(data->win_ptr, 2, 0, key_press, data);
	mlx_loop(data->mlx_ptr);
}