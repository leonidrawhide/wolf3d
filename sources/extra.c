/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:44:57 by apidgeot          #+#    #+#             */
/*   Updated: 2020/11/10 19:45:08 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

float	distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float	mod(float i)
{
	return ((i < 0) ? -i : i);
}

float	max1(float a, float b)
{
	return (a > b ? a : b);
}

float	min1(float a, float b)
{
	return (a < b ? a : b);
}

void	angle_checker(t_wolf *data)
{
	if (data->crd.ra < 0)
		data->crd.ra += 2 * PI;
	if (data->crd.ra > (2 * PI))
		data->crd.ra -= 2 * PI;
}
