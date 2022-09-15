# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 12:40:29 by aadnane           #+#    #+#              #
#    Updated: 2022/09/15 14:33:09 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c lis.c instructions.c push_lis.c utils.c pairing.c \
parsing_utils.c utils2.c distance_treatment.c sort.c sorting_utils.c \
five_under_treatement.c
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