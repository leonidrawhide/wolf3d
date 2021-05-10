/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:51:23 by khelen            #+#    #+#             */
/*   Updated: 2020/10/10 15:07:15 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	draw_3d(int r, t_wolf *data)
{
	int			i;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->crd.ca = data->ppos.pa - data->crd.ra;
	if (data->crd.ca < 0)
		data->crd.ca += 2 * PI;
	if (data->crd.ca > (2 * PI))
		data->crd.ca -= 2 * PI;
	data->crd.dist = data->kef * data->crd.dist * cos(data->crd.ca);
	data->ppos.lineh = ((data->map.height * data->map.width * HEIGHT)
	/ data->crd.dist);
	data->ppos.lineo = 0.6 * HEIGHT - data->ppos.lineh / 2;
	data->t.column = data->wall[data->w].img_width * data->t.hit
	/ data->map.block;
	i = 0;
	while (i < 8)
		draw_strip(r, i++, data);
}

int		get_color(t_wolf *data)
{
	int color;
	int c;

	c = ((int)data->t.t_y * data->wall[data->w].img_width + data->t.t_x) * 4;
	color = data->wall[data->w].addr[c];
	if (color == -120 && data->wall[data->w].addr[c + 1] == 0 &&
	data->wall[data->w].addr[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += data->wall[data->w].addr[c + 1] * 256;
	color += data->wall[data->w].addr[c + 2] * 256 * 256;
	return (color);
}

void	draw_wall(int y0, int x, int y1, t_wolf *data)
{
	int		color;

	data->t.ty_step = (float)data->wall[data->w].img_height / (float)(y1 - y0);
	data->t.t_x = data->t.column;
	data->t.t_y = 0;
	while (y0 <= y1)
	{
		color = get_color(data);
		if (color == 256 * 256 * 256 + 256 * 256 + 256)
			return ;
		data->color_f = color;
		extra_draw(y0, x, data);
		data->t.t_y = data->t.t_y + data->t.ty_step;
		y0++;
	}
}
