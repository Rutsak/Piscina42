NAME = a.out

HEADER = get_next_line.h

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra -D BUFFER_SIZE=10

SRCS =	main.c\
		get_next_line.c \
		get_next_line_utils.c\
		
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
	git add get*.c *.h
	cp *.c ~/copiesSeguretat/Piscina42/Get_Next_Line/
	cp *.h ~/copiesSeguretat/Piscina42/Get_Next_Line/
	cp Makefile ~/copiesSeguretat/Piscina42/Get_Next_Line/
	git status

.PHONY : clean all clean fclean re cs
