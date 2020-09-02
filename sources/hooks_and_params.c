/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:49:45 by khelen            #+#    #+#             */
/*   Updated: 2020/09/02 15:17:11 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Обрабатываем сигналы с клавиатуры.
*/

void	do_key(int key, t_wolf *data)
{
	if (key == 15)
		data->x = 1;
	if (key == 53)
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
	//print_thread_wolf(data);
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
	//print_thread_wolf(data);
	return (0);
}

/*
** Раскидваем сигналы мышки и клавиш по функциям.
*/

void	hooks_and_params(t_wolf *data)
{
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), red_butt, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_loop(data->mlx_ptr);
}