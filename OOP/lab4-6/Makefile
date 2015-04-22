NAME = program

SRCS =	main_t.cpp domain/part.cpp  \
	controller/controller.cpp ui/ui.cpp repository/repository.cpp

OBJS = $(SRCS:.cpp=.o)

OBJREG = *.o

CC = g++

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
