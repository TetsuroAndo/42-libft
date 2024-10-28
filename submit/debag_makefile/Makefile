# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 19:48:53 by teando            #+#    #+#              #
#    Updated: 2024/10/25 08:34:37 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard ft_*.c)
OBJ = $(SRC:.c=.o)
INCLUDES = -I.

BONUS_SRCS = $(wildcard *ft_lst*.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME) so

$(NAME): $(OBJ)
	ar rcs $@ $^

# $(NAME): $(OBJS)
# 	ar rcs $@ $^

# bonus: $(NAME) $(BONUS_OBJS)
# 	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re bonus