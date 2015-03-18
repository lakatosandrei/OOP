NAME = program

SRCS =	main_t.c domain/part.c domain/vector.c domain/iterator.c\
	controller/controller.c ui/ui.c repository/repository.c

OBJS = $(SRCS:.c=.o)

OBJREG = *.o

CC = gcc

FLAGS = -Wall -Wextra -Werror

CDEBUG = -g

CNAME = -o

RM = rm

RM_T = -f

all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) $(CNAME) $(NAME) $(SRCS) $(CDEBUG)

clean:
	$(RM) $(RM_T) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:fclean $(NAME)
