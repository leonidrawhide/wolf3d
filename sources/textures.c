/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:18:17 by apidgeot          #+#    #+#             */
/*   Updated: 2020/11/10 20:18:20 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	texture(t_wolf *data)
{
	data->wall[0].img = mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/wall0.xpm", &data->wall[0].img_width, &data->wall[0].img_height);
	data->wall[0].addr = mlx_get_data_addr(data->wall[0].img,
	&data->wall[0].bpp, &data->wall[0].size_l, &data->wall[0].endian);
	data->wall[1].img = mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/wall1.xpm", &data->wall[1].img_width, &data->wall[1].img_height);
	data->wall[1].addr = mlx_get_data_addr(data->wall[1].img,
	&data->wall[1].bpp, &data->wall[1].size_l, &data->wall[1].endian);
	data->wall[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/wall2.xpm", &data->wall[2].img_width, &data->wall[2].img_height);
	data->wall[2].addr = mlx_get_data_addr(data->wall[2].img,
	&data->wall[2].bpp, &data->wall[2].size_l, &data->wall[2].endian);
	data->wall[3].img = mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/wall3.xpm", &data->wall[3].img_width, &data->wall[3].img_height);
	data->wall[3].addr = mlx_get_data_addr(data->wall[3].img,
	&data->wall[3].bpp, &data->wall[3].size_l, &data->wall[3].endian);
}
