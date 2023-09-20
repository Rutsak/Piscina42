NAME = libftprintf.a

HEADER = ft_printf.h

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

SRCS =	ft_printf.c\
		s_label.c \
		i_label.c \
		p_label.c \
		d_label.c \

CORESRCS =	ft_printf.c\
			s_label.c \
			i_label.c \
			p_label.c \
			d_label.c \
			Makefile \
			ft_printf.h \

OBJS = $(SRCS:.c=.o)

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(HEADER)

all : $(NAME)

clean :
	rm -rf *.o
	rm -rf *.gch
	rm a.out

fclean : clean
	rm -f $(NAME)

re : fclean all

cs :
	git add $(CORESRCS)
	cp $(SRCS) ~/copiesSeguretat/Piscina42/printf/
	cp Makefile ~/copiesSeguretat/Piscina42/printf/
	git status

.PHONY : clean all clean fclean re cs