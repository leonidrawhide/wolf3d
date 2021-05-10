/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:49:49 by khelen            #+#    #+#             */
/*   Updated: 2020/11/12 17:52:40 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	horizontal_3(t_wolf *data)
{
	while (data->crd.dof < data->map.height)
	{
		data->crd.mx = (int)(data->rx) / data->map.block;
		data->crd.my = (int)(data->ry) / data->map.block;
		data->crd.mp = data->crd.my * data->map.width + data->crd.mx;
		if ((data->crd.mp > 0 && data->crd.mp < data->map.width *
		data->map.height && data->map.z_matrix[data->crd.my][data->crd.mx]
		== 1) || (data->crd.my == 0 || data->crd.my == data->map.height))
		{
			data->crd.hx = data->rx;
			data->crd.hy = data->ry;
			data->crd.dish = distance(data->ppos.px, data->ppos.py,
								data->crd.hx, data->crd.hy);
			data->crd.dof = data->map.height;
		}
		else
		{
			data->rx += data->xo;
			data->ry += data->yo;
			data->crd.dof++;
		}
	}
}

void	horizontal_2(t_wolf *data)
{
	if (data->crd.ra == PI || data->crd.ra == 0)
	{
		data->rx = data->ppos.px;
		data->ry = data->ppos.py;
		data->crd.dof = data->map.height;
	}
	horizontal_3(data);
}

void	horizontal(t_wolf *data)
{
	params_for_func(data, 1);
	if (data->crd.ra > PI)
	{
		data->ry = (int)data->ppos.py + (data->map.block - ((int)data->ppos.py
					% data->map.block)) - data->map.block - 0.0001;
		data->rx = (data->ppos.py - data->ry) * data->crd.atan + data->ppos.px;
		data->yo = -data->map.block;
		data->xo = -data->yo * data->crd.atan;
	}
	if (data->crd.ra < PI)
	{
		data->ry = (int)data->ppos.py + (data->map.block -
					((int)data->ppos.py % data->map.block));
		data->rx = (data->ppos.py - data->ry) * data->crd.atan + data->ppos.px;
		data->yo = data->map.block;
		data->xo = -data->yo * data->crd.atan;
	}
	horizontal_2(data);
}

void	vertical_2(t_wolf *data)
{
	while (data->crd.dof < data->map.width)
	{
		data->crd.mx = (int)(data->rx) / data->map.block;
		data->crd.my = (int)(data->ry) / data->map.block;
		data->crd.mp = data->crd.my * data->map.width + data->crd.mx;
		if ((data->crd.mp > 0 && data->crd.mp < data->map.width *
		data->map.height && data->map.z_matrix[data->crd.my][data->crd.mx]
		== 1) || (data->crd.mx == 0 || data->crd.mx == data->map.width))
		{
			data->crd.vx = data->rx;
			data->crd.vy = data->ry;
			data->crd.disv = distance(data->ppos.px, data->ppos.py,
			data->crd.vx, data->crd.vy);
			data->crd.dof = data->map.width;
		}
		else
		{
			data->rx += data->xo;
			data->ry += data->yo;
			data->crd.dof++;
		}
	}
}

void	vertical(t_wolf *data)
{
	params_for_func(data, 0);
	if (data->crd.ra > PI2 && data->crd.ra < PI3)
	{
		data->rx = (int)data->ppos.px + (data->map.block -
			((int)data->ppos.px % data->map.block)) - data->map.block - 0.0001;
		data->ry = (data->ppos.px - data->rx) * data->crd.ntan + data->ppos.py;
		data->xo = -data->map.block;
		data->yo = -data->xo * data->crd.ntan;
	}
	if (data->crd.ra < PI2 || data->crd.ra > PI3)
	{
		data->rx = (int)data->ppos.px + (data->map.block -
					((int)data->ppos.px % data->map.block));
		data->ry = (data->ppos.px - data->rx) * data->crd.ntan + data->ppos.py;
		data->xo = data->map.block;
		data->yo = -data->xo * data->crd.ntan;
	}
	if (data->crd.ra == PI || data->crd.ra == 0)
	{
		data->rx = data->ppos.px;
		data->ry = data->ppos.py;
		data->crd.dof = data->map.width;
	}
	vertical_2(data);
}
