# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 14:13:56 by doller-m          #+#    #+#              #
#    Updated: 2023/10/26 12:05:45 by doller-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = fdf.h

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

MINILIBX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

LIBFT = ./libft/libft.a

MINILIBX = ./mlx/libmlx.a

SRCS =	fdf.c\
		paint_fdf.c\

OBJS = $(SRCS:.c=.o)

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) -Imlx -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS) $(HEADER)
	make -C ./libft
	make -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) $(HEADER) ${LIBFT} ${MINILIBX} $(MINILIBX_FLAGS)
all : $(NAME)

clean :
	rm -rf *.o
	rm -rf *.gch
	rm a.out
	${MAKE} clean -C ./libft
	${MAKE} clean -C ./mlx

fclean : clean
	rm -f $(NAME)
	${MAKE} fclean -C ./libft

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

.PHONY : all clean fclean re cs
