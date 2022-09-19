# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 12:40:29 by aadnane           #+#    #+#              #
#    Updated: 2022/09/18 16:54:48 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c lis.c instructions.c push_lis.c utils.c pairing.c \
	parsing_utils.c utils2.c distance_treatment.c sort.c sorting_utils.c \
	five_under_treatement.c utils3.c aux_parse_utls.c gnl.c \

SRCB = checker.c lis.c instructions.c push_lis.c utils.c pairing.c \
	parsing_utils.c utils2.c distance_treatment.c sort.c sorting_utils.c \
	five_under_treatement.c utils3.c aux_parse_utls.c gnl.c checker_utls.c \

OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)
NAME = push_swap
BONUS = checker
HEADER = push_swap.h

all : $(NAME)

$(BONUS) : $(OBJB)
	$(CC) $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o  : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(OBJB)

fclean : clean
	rm -rf $(NAME) $(BONUS)

hoho :
	make && make clean && clear

b:
	make bonus && make clean && clear
bonus : $(BONUS)

re : fclean all