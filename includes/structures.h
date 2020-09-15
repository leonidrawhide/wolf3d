/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:14:18 by khelen            #+#    #+#             */
/*   Updated: 2020/09/15 16:54:54 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

typedef struct			s_ray
{
	int					num;
	int					length;
}						t_ray;

typedef struct	s_plrpos
{
	int 		px;
	int			py;
	float		pdx;
	float		pdy;
	float		pangle;
}				t_plrpos;

typedef struct	s_map
{
	int			width;
	int			height;
	int			**z_matrix;

	int			new_width;
	int			new_height;
}				t_map;

typedef struct	s_keyboard
{
	int			map_status;
	int			vision;
}				t_keyboard;

typedef	struct	s_wolf
{
	int			x;
	int			y;
	int			hipo;
	int			min;
	int			color;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	int			dist[FOV + 1];  // значения сохраняются здесь с нулевого по последнее
	int			bpp;
	int			size_l;
	int			endian;
	int			*img_d;
	int			**img_2d;
	t_plrpos	ppos;
	t_map		map;
	t_keyboard	keyboard;
	t_ray		ray;
	int			ray_count;
}				t_wolf;
