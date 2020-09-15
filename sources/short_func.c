/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:12:14 by khelen            #+#    #+#             */
/*   Updated: 2020/09/15 18:33:45 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	arrow_left(t_wolf *data)
{
	data->ppos.pangle -= 0.0177;
	if (data->ppos.pangle < 0)
		data->ppos.pangle += 2 * PI;
	data->ppos.pdx = cos(data->ppos.pangle) * 5;
	data->ppos.pdy = sin(data->ppos.pangle) * 5;
}

void	arrow_right(t_wolf *data)
{
	data->ppos.pangle += 0.0177;
	if (data->ppos.pangle > 2 * PI)
		data->ppos.pangle -= 2 * PI;
	data->ppos.pdx = cos(data->ppos.pangle) * 5;
	data->ppos.pdy = sin(data->ppos.pangle) * 5;
}

void	key_a(t_wolf *data, int count)
{
	//if (data->img_d[data->ppos.px * WIDTH + (data->ppos.py - count)] != 0xFF0000)
	data->ppos.py -= count;
}

void	key_d(t_wolf *data, int count)
{
	//if (data->img_d[data->ppos.px * WIDTH + (data->ppos.py + count)] != 0xFF0000)
	data->ppos.py += count;
}

void	go_up(t_wolf *data)
{
	float n;

	n = data->ppos.pangle + 0.0177 * FOV / 2;
	n = (data->ppos.pangle + 0.0177 * FOV / 2) > PI * 2 ? n - PI * 2 : n;
	data->ppos.px += cos(data->ppos.pangle + 0.0177 * FOV / 2) * 5;
	data->ppos.py += sin(data->ppos.pangle + 0.0177 * FOV / 2) * 5;
}

void	go_down(t_wolf *data)
{
	float n;
	
	n = data->ppos.pangle + 0.0177 * FOV / 2;
	n = (data->ppos.pangle + 0.0177 * FOV / 2) > PI * 2 ? n - PI * 2 : n;
	data->ppos.px -= cos(data->ppos.pangle + 0.0177 * FOV / 2) * 5;
	data->ppos.py -= sin(data->ppos.pangle + 0.0177 * FOV / 2) * 5;
}
