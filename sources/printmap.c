/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:51:23 by khelen            #+#    #+#             */
/*   Updated: 2020/09/05 15:58:57 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			printvision(t_wolf *data)
{
	float	x;
	float	y;

	x = data->ppos.px + data->ppos.pdx * 5;
	y = data->ppos.py + data->ppos.pdy * 5;
	draw_rays(data);
}

void			printlab(t_wolf *data)
{
	int w;
	int h;

	w = data->x / data->map.block;
	h = data->y / data->map.block;
}
