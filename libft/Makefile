# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 10:17:53 by doller-m          #+#    #+#              #
#    Updated: 2023/05/16 15:39:35 by doller-m         ###   ########.fr        #
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
		ft_isdigit.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
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

%.o : %.c
	$(CC) -c -MD $(CFLAGS) $< -o $@

-include *.d

$(NAME) : $(OBJS)
	ar -crs $(NAME) $(OBJS)

all :
	$(CC) -c $(CFALGS) $(SRCS) $(HEADER)

clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : fclean all


.PHONY : clean all clean fclean re
