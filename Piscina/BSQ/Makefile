CC=cc
NAME=bsq
SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))
FLAGS=-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(FLAGS) -o $@ $^

norm:
		norminette -R CheckForbiddenSourceHeader *.c
		norminette -R CheckDefine *.h

test:
		./$(NAME) ./map/map1

clean :
		rm -vf *.o

fclean: clean
		rm -vf $(NAME)
