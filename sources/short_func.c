/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:12:14 by khelen            #+#    #+#             */
/*   Updated: 2020/09/07 15:18:02 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	arrow_left(t_wolf *data)
{
	data->ppos.pangle -= 0.1;
	if (data->ppos.pangle < 0)
		data->ppos.pangle += 2 * PI;
	data->ppos.pdx = cos(data->ppos.pangle) * 5;
	data->ppos.pdy = sin(data->ppos.pangle) * 5;
}

void	arrow_right(t_wolf *data)
{
	data->ppos.pangle += 0.1;
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
	data->ppos.px += data->ppos.pdx;
	data->ppos.py += data->ppos.pdy;
}

void	go_down(t_wolf *data)
{
	data->ppos.px -= data->ppos.pdx;
	data->ppos.py -= data->ppos.pdy;
}
