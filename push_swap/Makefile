# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 15:16:14 by doller-m          #+#    #+#              #
#    Updated: 2024/01/08 17:41:40 by doller-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

HEADER = push_swap.h

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra #-fsanitize='address,undefined'

LIBFT_PATH = libft/

LIBFT = $(LIBFT_PATH)libft.a

SRCS =	push_swap.c\

OBJS = $(SRCS:.c=.o)

all : subsystem $(NAME)

%.o : %.c $(HEADER) Makefile
	$(CC) -c $(CFLAGS) -I -c $< -o $@

$(NAME) : $(OBJS)

	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


subsystem :
	make -C $(LIBFT_PATH) all

clean :
	rm -rf *.o
	rm -rf *.gch
	$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all

cs :
	make fclean
	git add *.c *.h Makefile
	cp *.c ~/copiesSeguretat/Piscina42/push_swap/
	cp *.h ~/copiesSeguretat/Piscina42/push_swap/
	cp Makefile ~/copiesSeguretat/Piscina42/push_swap/
	cp -r libft ~/copiesSeguretat/Piscina42/push_swap/
	git status

.PHONY : all clean fclean re cs subsystem