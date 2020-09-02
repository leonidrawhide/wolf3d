/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:20:55 by khelen            #+#    #+#             */
/*   Updated: 2020/09/02 15:32:58 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define HEIGHT 1000
# define WIDTH 1000
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef	struct	s_wolf
{
	int			x;
	int			y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	int			bpp;
	int			size_l;
	int			endian;
	int			*img_d;
	int			thread_id;
}				t_wolf;

int		main(void);
int		red_butt(t_wolf *data);
void	default_params(t_wolf *data);
void	do_key(int key, t_wolf *data);
void	hooks_and_params(t_wolf *data);
int		deal_key(int key, t_wolf *data);
int		mouse_hook(int mousecode, int x, int y, t_wolf *data);

#endif