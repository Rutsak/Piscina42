NAME = get_next_line.a

HEADER = get_next_line.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42

SRCS =	get_next_line.c \
		get_next_line_utils.c\

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
	git add get*.c *.h
	cp *.c ~/copiesSeguretat/Piscina42/Get_Next_Line/
	cp *.h ~/copiesSeguretat/Piscina42/Get_Next_Line/
	cp Makefile ~/copiesSeguretat/Piscina42/Get_Next_Line/
	git status

.PHONY : clean all clean fclean re cs
