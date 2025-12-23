# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digonza2 <digonza2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/23 17:35:38 by digonza2          #+#    #+#              #
#    Updated: 2025/12/23 18:51:35 by digonza2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

FILES = get_next_line.c \
		get_next_line_utils.c \

BONUS_FILES =	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \

OBJECTS = $(FILES:.c=.o)

BONUS_OBJECTS = $(BONUS_FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = cc

INPUT ?= main.c

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(BONUS_OBJECTS) *.out

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(FLAGS) $(INPUT) $(NAME) -o test.out

testbonus: bonus
	$(CC) -g $(FLAGS) $(INPUT) $(NAME) -o testbonus.out


cleantest:

.PHONY: all bonus clean fclean re