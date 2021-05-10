/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:20:55 by khelen            #+#    #+#             */
/*   Updated: 2020/11/12 18:00:35 by khelen           ###   ########.fr       */
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
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define HEIGHT 800
# define WIDTH 960
# define BLOCK 48
# define PI 3.141592
# define PI2 PI/2
# define PI3 3*PI/2
# define DR 0.0174533

# define ESC 53
# define L_SHIFT 257
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define SPACE 49
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define M_KEY 46
# define RETURN 36

typedef struct		s_plrpos
{
	float			px;
	float			py;
	float			pdx;
	float			pdy;
	float			pa;
	float			mpp;
	int				head_pos;
	float			lineh;
	float			lineo;
}					t_plrpos;

typedef struct		s_map
{
	int				width;
	int				height;
	int				**z_matrix;

	int				new_width;
	int				new_height;
	int				block;
}					t_map;

typedef struct		s_keyboard
{
	int				map_status;
	int				vision;
	int				mx;
	int				my;
}					t_keyboard;

typedef struct		s_coordinates
{
	int				dof;
	int				mx;
	int				my;
	int				mp;
	float			ra;
	float			atan;
	float			ntan;
	float			dish;
	float			disv;
	float			hx;
	float			hy;
	float			vx;
	float			vy;
	float			ca;
	float			dist;
	float			rrx;
	float			rry;
}					t_coordinates;

typedef struct		s_texture
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size_l;
	int				endian;
	int				img_width;
	int				img_height;
}					t_texture;

typedef struct		s_text
{
	int				hit;
	int				column;
	float			ty_step;
	int				t_x;
	float			t_y;
}					t_text;

typedef	struct		s_wolf
{
	int				x;
	int				y;
	int				w;
	float			rx;
	float			ry;
	float			yo;
	float			xo;
	int				min;
	int				color;
	int				color_f;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_img;
	int				bpp;
	int				size_l;
	int				endian;
	char			*img_d;
	int				count;
	int				kef;
	t_plrpos		ppos;
	t_map			map;
	t_keyboard		keyboard;
	t_coordinates	crd;
	t_text			t;
	t_texture		wall[4];
}					t_wolf;

int					main(int ac, char **av);
void				printmap(t_wolf *data);
int					red_button(t_wolf *data);
void				*print_wolf(void *data);
void				default_params1(t_wolf *data);
void				default_params2(t_wolf *data);
int					do_key(int key, void *data);
void				hooks_and_params(t_wolf *data);
int					print_thread_wolf(t_wolf *data);
int					deal_key(int key, t_wolf *data);
void				read_file(char *file_name, t_wolf *data);
int					mouse_hook(int mousecode, int x, int y, t_wolf *data);
float				min1(float a, float b);
float				mod(float i);
float				max1(float a, float b);
float				distance(float ax, float ay, float bx, float by);
void				draw_rays(t_wolf *data);
void				printlab(t_wolf *data);
void				printvision(t_wolf *data);
void				draw_3d(int r, t_wolf *data);
void				draw_floor(float x0, float y0, float y1,
t_wolf *data);
void				draw_ceil(float x0, float y0, float y1,
t_wolf *data);
void				extra_draw(float y0, float x0, t_wolf *data);
void				filling(t_wolf *data);
void				draw_strip(int r, int i, t_wolf *data);
void				draw_line(t_wolf *data);
void				angle_checker(t_wolf *data);
void				comparison(t_wolf *data);
int					start_check(t_wolf *data);
void				draw_wall(int y0, int x, int y1, t_wolf *data);
void				texture(t_wolf *data);
void				check_xy(t_wolf *data);
void				error_and_free(char *str, t_wolf *data);
void				free_rf(int i, t_wolf *data);
void				check_digits(t_wolf *data);
int					mouse_motion(int x, int y, t_wolf *data);
void				key1(int key, t_wolf *data);
void				key2(int key, t_wolf *data);
void				key3(t_wolf *data);
void				vertical(t_wolf *data);
void				horizontal(t_wolf *data);
void				params_for_func(t_wolf *data, int hor_ver);

#endif
