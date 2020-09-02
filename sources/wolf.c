/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:20:59 by khelen            #+#    #+#             */
/*   Updated: 2020/09/02 15:17:15 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Начало вульфа. Выделяем память, задаем дефолтные параметры, создаем
** "Полотно" для рисования рейкастера. Печатаем его, вызываем функция для 
** проверки нажатий клавиш.
*/

int		main(void)
{
	t_wolf *data;

	if (!(data = (t_wolf*)malloc(sizeof(t_wolf) + 1)))
	{
		free(data);
		ft_putstr("Error! Memory for data was not allocated.\n");
		exit(0);
	}
	default_params(data);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img_d = (int *)mlx_get_data_addr(data->mlx_img, &data->bpp,
		&data->size_l, &data->endian);
	//print_thread_wolf(data);
	hooks_and_params(data);
	return (0);
}