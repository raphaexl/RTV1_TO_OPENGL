# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 16:42:41 by ebatchas          #+#    #+#              #
#    Updated: 2019/10/23 16:57:41 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rtv1

CC      = gcc

PWD = \"$(shell pwd)\"

SRCDIR   = srcs
OBJDIR   = objs
BINDIR   = .
INCLUDESDIR = incs

LIBGLMATHDIR = libglmath
LIBGLMATH_INCLUDEDIR = inc
LIBGLMATH = $(LIBGLMATHDIR)/libglmath.a
LIBVECTORDIR = libvector
LIBVECTOR_INCLUDEDIR = inc
LIBVECTOR = $(LIBVECTORDIR)/libvector.a
LIBFTDIR = libft
LIBFT_INCLUDEDIR = inc
LIBFT = $(LIBFTDIR)/libft.a
LIBGLEWDIR = ~/.brew/Cellar/glew/2.1.0
LIBGLEW_INCLUDEDIR = include
LIBGLEW = $(LIBGLEWDIR)/lib/libGLEW.a
LIBGLFWDIR = ~/.brew/Cellar/glfw/3.3
LIBGLFW_INCLUDEDIR = include
LIBGLFW = $(LIBGLFWDIR)/lib/
LIBSDL2DIR = ~/.brew/Cellar/sdl2/2.0.10
LIBSDL2_INCLUDEDIR = include
LIBSDL2 = $(LIBSDL2DIR)/lib/
LIBSDL2_IMAGE_DIR = ~/.brew/Cellar/sdl2_image/2.0.5
LIBSDL2_IMAGE_INCLUDEDIR = include
LIBSDL2_IMAGE = $(LIBSDL2_IMAGE_DIR)/lib/

OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX = input.c main.c opengl.c run.c shader_tools.c shader_utils.c\
					shader.c tga.c utils.c camera.c call_backs.c \
					quad.c uniform.c cam.c objects.c scene.c

INCLUDES_NO_PREFIX = opengl.h utils.h defines.h quad.h structs.h material.h rtv1.h

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))

INC = -I $(INCLUDESDIR) -I $(LIBGLMATHDIR)/$(LIBGLMATH_INCLUDEDIR)\
		-I $(LIBVECTORDIR)/$(LIBVECTOR_INCLUDEDIR) -I $(LIBFTDIR)/$(LIBFT_INCLUDEDIR)\
		-I $(LIBGLFWDIR)/$(LIBGLFW_INCLUDEDIR) -I $(LIBGLEWDIR)/$(LIBGLEW_INCLUDEDIR)\
		-I $(LIBSDL2DIR)/$(LIBSDL2_INCLUDEDIR) -I $(LIBSDL2_IMAGE_DIR)/$(LIBSDL2_IMAGE_INCLUDEDIR)

CFLAGS = -DPATH=$(PWD) -Wall -Wextra -Werror $(INC)
LFLAGS = -L $(LIBGLMATHDIR) -L $(LIBVECTORDIR) -L $(LIBFTDIR) -L $(LIBGLEWDIR)/lib\
		 -L $(LIBGLFWDIR)/lib -L $(LIBSDL2DIR)/lib -L $(LIBSDL2_IMAGE_DIR)/lib \
		 -lglmath -lvector -lft -lm -lGLEW -lglfw -lSDL2 -lSDL2_image -framework OPENGL

all:
	@make -C $(LIBGLMATHDIR) all
	@make -C $(LIBVECTORDIR) all
	@make -C $(LIBFTDIR) all
	@make $(BINDIR)/$(NAME)

$(LIBGLMATH):
	@make -C $(LIBGLMATHDIR) all

$(LIBVECTOR):
	@make -C $(LIBVECTORDIR) all

$(LIBFT):
	@make -C $(LIBFTDIR) all

$(BINDIR)/$(NAME): $(OBJECTS) $(LIBGLMATH) $(LIBVECTOR) $(LIBFT)
	@$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS) 

clean:
	@make clean -C $(LIBGLMATHDIR)
	@make clean -C $(LIBVECTORDIR)
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJECTS)
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBGLMATHDIR)
	@make fclean -C $(LIBVECTORDIR)
	@make fclean -C $(LIBFTDIR)
	@rm -f $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
