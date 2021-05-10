/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:51:23 by khelen            #+#    #+#             */
/*   Updated: 2020/11/12 17:50:30 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	params_for_func(t_wolf *data, int hor_ver)
{
	if (hor_ver == 0)
	{
		data->crd.dof = 0;
		data->crd.disv = 100000;
		data->crd.vx = data->ppos.px;
		data->crd.vy = data->ppos.py;
		data->crd.ntan = -tan(data->crd.ra);
	}
	else if (hor_ver == 1)
	{
		data->crd.dof = 0;
		data->crd.dish = 100000;
		data->crd.hx = data->ppos.px;
		data->crd.hy = data->ppos.py;
		data->crd.atan = -1 / tan(data->crd.ra);
	}
}

void	hit(t_wolf *data)
{
	if (data->w < 2)
		data->t.hit = (int)data->crd.vy % data->map.block;
	else
		data->t.hit = (int)data->crd.hx % data->map.block;
}

void	comparison(t_wolf *data)
{
	if (data->crd.dish >= data->crd.disv)
	{
		data->crd.rrx = data->crd.vx;
		data->crd.rry = data->crd.vy;
		data->crd.dist = data->crd.disv;
		if (data->map.z_matrix[(int)(data->crd.rry) /
		data->map.block][(int)(data->crd.rrx + 1) / data->map.block] == 0)
			data->w = 0;
		else
			data->w = 1;
	}
	if (data->crd.dish < data->crd.disv)
	{
		data->crd.rrx = data->crd.hx;
		data->crd.rry = data->crd.hy;
		data->crd.dist = data->crd.dish;
		if (data->map.z_matrix[(int)(data->crd.rry - 1) /
		data->map.block][(int)(data->crd.rrx) / data->map.block] == 0)
			data->w = 2;
		else
			data->w = 3;
	}
	hit(data);
}

void	draw_rays(t_wolf *data)
{
	int r;

	data->crd.ra = data->ppos.pa - 30 * DR;
	angle_checker(data);
	r = 0;
	while (r < 120)
	{
		horizontal(data);
		vertical(data);
		comparison(data);
		draw_3d(r, data);
		data->crd.ra += DR / 2;
		angle_checker(data);
		r++;
	}
}
