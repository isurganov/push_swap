# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 00:33:16 by Arbiter           #+#    #+#              #
#    Updated: 2022/03/02 21:56:55 by Arbiter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

SRC = push_swap.c detect.c big1.c big.c average.c\
		cmd1.c cmd2.c cmd3.c ft_atoi.c ft_split.c\
		ft_isdigit.c utils.c checker.c new_n.c 

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

.c.o:
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(HEADER) $(OBJ) Makefile
	@cc $(FLAGS) $(OBJ) -o $@ -O2 
	@echo "push_swap is ready to roll!"

clean:
	@rm -f $(OBJ)
	@echo "OBJS are dead"

fclean: clean
	@rm -f $(NAME)
	@echo "push_swap is dead"

re: fclean all

.PHONY: all clean fclean re