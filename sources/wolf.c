/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:20:59 by khelen            #+#    #+#             */
/*   Updated: 2020/10/10 15:46:40 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

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

int		start_check(t_wolf *data)
{
	int x;
	int y;

	x = (int)(data->ppos.px) / data->map.block;
	y = (int)(data->ppos.py) / data->map.block;
	if (data->map.z_matrix[y][x] != 0)
	{
		ft_putstr("Error! Incorrect map! Central value of map must be 0.\n");
		free(data);
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_wolf		*data;

	if (ac != 2 || av[1] == NULL)
	{
		ft_putstr("Argument error.\n");
		exit(0);
	}
	legit_check(av[1]);
	if (!(data = (t_wolf*)malloc(sizeof(t_wolf) + 1)))
	{
		ft_putstr("Error! Memory for data was not allocated.\n");
		red_button(data);
	}
	read_file(av[1], data);
	default_params1(data);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img_d = mlx_get_data_addr(data->mlx_img, &data->bpp, &data->size_l,
	&data->endian);
	texture(data);
	print_thread_wolf(data);
	hooks_and_params(data);
	return (0);
}
