# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 23:27:31 by lmunoz-q          #+#    #+#              #
#    Updated: 2018/04/26 13:54:34 by lmunoz-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Ofast -Wall -Wextra -Werror

CLIB = -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCFILES = main.c \
		   fish.c \
		   julia.c \
		   mandelbrot.c \
		   burningship.c \
		   fractale.c \
		   sea_lion.c \
		   init.c \
		   gratio.c \
		   appratio.c \
		   mouse_hook.c \
		   refresh.c \
		   key_hook.c \
		   name.c \
		   lock_hook.c \
		   color.c \
		   motion.c \
		   boule.c \

INC = inc \

DIRS = event \
	   fractals \
	   operations \
	   color \

INCDIRS = $(addprefix -I,$(INC))

OBJDIR = obj

OBJECTS = $(SRCFILES:%.c=$(OBJDIR)/%.o)

SRCDIRS := $(addprefix src/,$(DIRS))

vpath %.c src $(SRCDIRS)

all: $(NAME)

$(NAME): libft/libft.a minilibx_macos/libmlx.a $(OBJECTS)
	$(CC) $(INCDIRS) $(CLIB) -o $@ $(OBJECTS)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(INCDIRS) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

libft/libft.a: force
	$(MAKE) -w -C libft/
	$(MAKE) -w -C minilibx_macos/

minilibx_macos/libmlx.a: force
	$(MAKE) -w -C minilibx_macos/

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -w -C libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -w -C libft/ fclean

re: fclean all

force:
	true

.PHONY: all clean fclean re
