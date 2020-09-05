/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:20:59 by khelen            #+#    #+#             */
/*   Updated: 2020/09/05 15:15:12 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

/*
** Проверка на "нормальность" файла
*/

void	legit_check(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_putstr("Error\n");
		close(fd);
		exit(0);
	}
	else
		close(fd);
}

/*
** Начало вульфа. Выделяем память, задаем дефолтные параметры, создаем
** "Полотно" для рисования. Печатаем его, вызываем функция для 
** проверки нажатий клавиш.
*/

int		main(int ac, char **av)
{
	t_wolf *data;

	if (ac != 2 || av[1] == NULL)
	{
		ft_putstr("Argument error.\n");
		exit(0);
	}
	legit_check(av[1]);
	if (!(data = (t_wolf*)malloc(sizeof(t_wolf) + 1)))
	{
		free(data);
		ft_putstr("Error! Memory for data was not allocated.\n");
		exit(0);
	}
	read_file(av[1], data);
	default_params(data);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img_d = (int *)mlx_get_data_addr(data->mlx_img, &data->bpp,
		&data->size_l, &data->endian);
	print_thread_wolf(data);
	hooks_and_params(data);
	return (0);
}