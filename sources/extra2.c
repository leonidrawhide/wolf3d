/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:45:20 by apidgeot          #+#    #+#             */
/*   Updated: 2020/11/10 19:45:22 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	free_rf(int i, t_wolf *data)
{
	free(data->map.z_matrix[i]);
	data->map.z_matrix[i] = NULL;
}

void	check_y(t_wolf *data)
{
	int		y;

	y = 0;
	while (y < data->map.height)
	{
		if (data->map.z_matrix[y][0] == 0)
			error_and_free("Error! Illegal map.\n", data);
		y++;
	}
	y = 0;
	while (y < data->map.height)
	{
		if (data->map.z_matrix[y][data->map.width - 1] == 0)
			error_and_free("Error! Illegal map.\n", data);
		y++;
	}
}

int		red_button(t_wolf *data)
{
	free(data);
	exit(0);
}

void	check_x(t_wolf *data)
{
	int		x;

	x = 0;
	while (x < data->map.width)
	{
		if (data->map.z_matrix[0][x] == 0)
			error_and_free("Error! Illegal map.\n", data);
		x++;
	}
	x = 0;
	while (x < data->map.width)
	{
		if (data->map.z_matrix[data->map.height - 1][x] == 0)
			error_and_free("Error! Illegal map.\n", data);
		x++;
	}
}

void	check_xy(t_wolf *data)
{
	check_digits(data);
	check_x(data);
	check_y(data);
}
