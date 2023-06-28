# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovoa <anovoa@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 22:37:08 by anovoa            #+#    #+#              #
#    Updated: 2023/04/15 23:06:17 by anovoa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = ft_errors.c ft_putchars.c ft_read_dict.c ft_checks.c ft_numbers.c \
	  main.c

MAIN_DICTIONARY = numbers.dict


all: $(NAME)

$(NAME):
	@cc -o $(NAME) -Wall -Wextra -Werror $(SRC)

clean:
	@find . -name $(NAME) -delete

fclean: clean
	@find data -name *.dict -not -name $(MAIN_DICTIONARY) -delete

re: fclean all
