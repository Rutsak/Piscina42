# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 10:17:53 by doller-m          #+#    #+#              #
#    Updated: 2023/05/19 15:49:06 by doller-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =	ft_atoi.c \
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_isdigit.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
	   	ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\

OBJS = $(SRCS:.c=.o)

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

cs :
	git add *.c *.h Makefile
	cp *.c ~/copiesSeguretat/Piscina42/libft/
	cp *.h ~/copiesSeguretat/Piscina42/libft/
	cp Makefile ~/copiesSeguretat/Piscina42/libft/
	git status

.PHONY : clean all clean fclean re cs
