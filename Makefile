# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khelen <khelen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 14:26:54 by khelen            #+#    #+#              #
#    Updated: 2020/11/12 17:52:12 by khelen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -O3
LIBRARIES	= -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES	= -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT		= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = wolf.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = wolf.c default_params.c hooks_and_params.c print.c read_file.c printmap.c extra.c draw.c rays.c rays_calculation.c textures.c extra2.c hooks.c other.c extra_draw.c 
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME) ||:
	@echo "$(NAME) was created"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY) ||:

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@ ||:

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY) ||:

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) ||:

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(OBJECTS_DIRECTORY) folder was deleted"
	@echo "object files were deleted"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(MINILIBX) was deleted"
	@rm -f $(LIBFT)
	@echo "$(LIBFT) was deleted"
	@rm -f $(NAME)
	@echo "$(NAME) was deleted"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean flcean re%  