/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:20:55 by khelen            #+#    #+#             */
/*   Updated: 2020/09/04 17:51:42 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include "macros.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct	s_plrpos
{
	int 		px;
	int			py;
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
}				t_keyboard;

typedef	struct	s_wolf
{
	int			x;
	int			y;
	int			min;
	int			color;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	int			bpp;
	int			size_l;
	int			endian;
	int			*img_d;
	t_plrpos	ppos;
	t_map		map;
	t_keyboard	keyboard;
}				t_wolf;

				

int		main(int ac, char **av);

void	printmap(t_wolf *data);
int		red_butt(t_wolf *data);
void	*print_wolf(void *data);
void	default_params(t_wolf *data);
void	do_key(int key, t_wolf *data);
void	hooks_and_params(t_wolf *data);
int		print_thread_wolf(t_wolf *data);
int		deal_key(int key, t_wolf *data);
void	read_file(char *file_name, t_wolf *data);
int		mouse_hook(int mousecode, int x, int y, t_wolf *data);


#endif