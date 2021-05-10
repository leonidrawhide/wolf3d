/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:00:36 by apidgeot          #+#    #+#             */
/*   Updated: 2020/11/12 17:00:40 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_strip(int r, int i, t_wolf *data)
{
	draw_ceil(r * 8 + i, 0, data->ppos.lineo +
	data->ppos.head_pos, data);
	draw_wall(data->ppos.lineo + data->ppos.head_pos, r * 8 + i,
	data->ppos.lineh + data->ppos.lineo + data->ppos.head_pos, data);
	draw_floor(r * 8 + i, data->ppos.lineh + data->ppos.lineo +
	data->ppos.head_pos - 1, HEIGHT + 1, data);
}

void	draw_ceil(float x0, float y0, float y1, t_wolf *data)
{
	float	x_step;
	float	y_step;
	float	x1;

	x1 = x0;
	x_step = x1 - x0;
	y_step = y1 - y0;
	x_step /= max1(mod(x_step), mod(y_step));
	y_step /= max1(mod(x_step), mod(y_step));
	while ((int)(x1 - x0) != 0 || (int)(y1 - y0) != 0)
	{
		data->color_f = 0x66CCFF;
		extra_draw(y0, x0, data);
		if (x1 < x0)
			x0 -= mod(x_step);
		else if (x1 > x0)
			x0 += x_step;
		if (y1 < y0)
			y0 -= mod(y_step);
		else if (y1 > y0)
			y0 += y_step;
	}
}

void	extra_draw(float y0, float x0, t_wolf *data)
{
	int		b;
	int		g;
	int		r;
	int		c;

	b = data->color_f % 256;
	g = (data->color_f / 256) % 256;
	r = (data->color_f / 256 / 256) % 256;
	c = (int)y0 * data->size_l + ((int)x0 * (data->bpp / 8));
	if (!(c > WIDTH * HEIGHT * 4 || c < 0))
	{
		data->img_d[c] = b;
		data->img_d[c + 1] = g;
		data->img_d[c + 2] = r;
	}
}

void	draw_floor(float x0, float y0, float y1, t_wolf *data)
{
	float	x_step;
	float	y_step;
	float	x1;

	x1 = x0;
	x_step = x1 - x0;
	y_step = y1 - y0;
	x_step /= max1(mod(x_step), mod(y_step));
	y_step /= max1(mod(x_step), mod(y_step));
	while ((int)(x1 - x0) != 0 || (int)(y1 - y0) != 0)
	{
		data->color_f = 0x999966;
		extra_draw(y0, x0, data);
		if (x1 < x0)
			x0 -= mod(x_step);
		else if (x1 > x0)
			x0 += x_step;
		if (y1 < y0)
			y0 -= mod(y_step);
		else if (y1 > y0)
			y0 += y_step;
	}
}
