/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:54:02 by khelen            #+#    #+#             */
/*   Updated: 2020/10/08 16:39:31 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	get_height_width(char *file_name, t_wolf *data)
{
	char	*line;
	int		fd;
	int		height;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		if (height == 0)
			width = ft_wdcounter(line, ' ');
		height++;
		free(line);
	}
	if (line != NULL)
		free(line);
	close(fd);
	data->map.height = height;
	data->map.width = width;
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums[i]);
	free(nums);
}

void	error_and_free(char *str, t_wolf *data)
{
	ft_putstr(str);
	free(data);
	exit(0);
}

void	check_digits(t_wolf *data)
{
	int		x;
	int		y;

	if (data->map.height < 3 || data->map.height < 3)
		error_and_free("Error! Illegal map.\n", data);
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.z_matrix[y][x] == 0)
				return ;
			x++;
		}
		y++;
	}
	error_and_free("Error! Illegal map.\n", data);
}

void	read_file(char *file_name, t_wolf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	get_height_width(file_name, data);
	if (!(data->map.z_matrix = (int **)malloc(sizeof(int*) *
	(data->map.height + 1))))
		error_and_free("Error!\n", data);
	while (i <= data->map.height)
		if (!(data->map.z_matrix[i++] = (int*)malloc(sizeof(int) *
		(data->map.width + 1))))
			error_and_free("Error!\n", data);
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->map.z_matrix[i++], line);
		free(line);
	}
	check_xy(data);
	if (line != NULL)
		free(line);
	close(fd);
	free_rf(i, data);
}
