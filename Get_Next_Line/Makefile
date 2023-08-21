NAME = a.out

HEADER = get_next_line.h

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra -D BUFFER_SIZE=1

SRCS =	main.c\
		get_next_line.c \
		get_next_line_utils.c\
		
OBJS = $(SRCS:.c=.o)

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

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
	git commit -m 'automatic de casa'
	git status
	git log --oneline --pretty --graph --decorate --all
	
.PHONY : clean all clean fclean re cs
