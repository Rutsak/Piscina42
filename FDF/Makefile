# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 14:13:56 by doller-m          #+#    #+#              #
#    Updated: 2023/12/11 15:02:41 by doller-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = fdf.h

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra #-fsanitize='address,undefined'

MINILIBX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a

MINILIBX_PATH = ./mlx/

MINILIBX = $(MINILIBX_PATH)libmlx.a

SRCS =	fdf.c\
		paint_fdf.c\
		3d_fdf.c\
		map_utils.c\
		matrius.c\
		hooks.c\

OBJS = $(SRCS:.c=.o)

all : subsystem $(NAME)

%.o : %.c $(HEADER) Makefile
	$(CC) -c $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) 
	
	$(CC) $(CFLAGS) $(MINILIBX_FLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)


subsystem : 
	make -C $(LIBFT_PATH) all
	make -C $(MINILIBX_PATH) all

clean :
	rm -rf *.o
	rm -rf *.gch
	$(MAKE) -C $(MINILIBX_PATH) clean 
	$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_PATH) clean 
	$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all

cs :
	make fclean
	git add *.c *.h Makefile
	cp *.c ~/copiesSeguretat/Piscina42/FDF/
	cp *.h ~/copiesSeguretat/Piscina42/FDF/
	cp Makefile ~/copiesSeguretat/Piscina42/FDF/
	cp -r libft ~/copiesSeguretat/Piscina42/FDF/
	cp -r mlx ~/copiesSeguretat/Piscina42/FDF/
	git status

.PHONY : all clean fclean re cs subsystem
