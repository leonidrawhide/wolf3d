/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:20:55 by khelen            #+#    #+#             */
/*   Updated: 2020/09/14 18:23:54 by khelen           ###   ########.fr       */
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
# include "structures.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"				

int		main(int ac, char **av);

void	printmap(t_wolf *data);
void	printvision(t_wolf *data);
int		red_butt(t_wolf *data);
void	error_and_free(t_wolf *data);
void	*print_wolf(void *data);
void	default_params(t_wolf *data);
void	do_key(int key, t_wolf *data);
void	hooks_and_params(t_wolf *data);
int		print_thread_wolf(t_wolf *data);
int		deal_key(int key, t_wolf *data);
void	read_file(char *file_name, t_wolf *data);
int		mouse_hook(int mousecode, int x, int y, t_wolf *data);
void	print_raycaster(void *data);

void	arrow_left(t_wolf *data);
void	arrow_right(t_wolf *data);
void	key_a(t_wolf *data, int count);
void	key_d(t_wolf *data, int count);
void	go_up(t_wolf *data);
void	go_down(t_wolf *data);

#endif