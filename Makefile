CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c lis.c instructions.c push_lis.c utils.c pairing.c \
parsing_utils.c utils2.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
HEADER = push_swap.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o  : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(OBJSB)

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all