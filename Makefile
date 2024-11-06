# **************************************************************************** #
#																		      #
#														 :::      ::::::::    #
#    Makefile									       :+:      :+:    :+:    #
#												     +:+ +:+		 +:+      #
#    By: teando <teando@student.42tokyo.jp>		 +#+  +:+       +#+		 #
#												 +#+#+#+#+#+   +#+			#
#    Created: 2024/11/04 17:21:55 by teando			#+#    #+#			  #
#    Updated: 2024/11/04 23:00:52 by teando		   ###   ########.fr		#
#																		      #
# **************************************************************************** #

UNAME_OS	:= $(shell uname -s)
NAME		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
LIBFT_H		:= libft.h
ROOT_DIR	:= .
INCS_DIR	:= $(ROOT_DIR)/incs
OUT_DIR		:= $(ROOT_DIR)/out
INCLUDES	:= -I $(INCS_DIR)

ifeq ($(UNAME_OS), Darwin)
NAME_SO		:= libft.dylib
else
NAME_SO		:= libft.so
endif

SRCS 		:= \
	$(addprefix $(ROOT_DIR)/, \
		$(addprefix ft_ctype/, \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isblank.c \
			ft_iscntrl.c \
			ft_isdigit.c \
			ft_isgraph.c \
			ft_islower.c \
			ft_isprint.c \
			ft_ispunct.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_isxdigit.c \
			ft_tolower.c \
			ft_toupper.c \
		) \
		$(addprefix ft_stdio/, \
			ft_getc.c \
			ft_putc.c \
			ft_putchar_fd.c \
			ft_putchar.c \
			ft_putendl_fd.c \
			ft_putendl.c \
			ft_putnbr_fd.c \
			ft_putnbr.c \
			ft_putstr_fd.c \
		) \
		$(addprefix ft_stdlib/, \
			ft_abs.c \
			ft_atoi.c \
			ft_atol.c \
			ft_atof.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_ltoa.c \
			ft_ftoa.c \
		) \
		$(addprefix ft_string/, \
			ft_bzero.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strndup.c \
			ft_strnlen.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
		) \
	)
OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.d))

BONUS_SRC	:= \
	$(addprefix $(ROOT_DIR)/, \
		$(addprefix ft_lst/, \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
		) \
	)
BONUS_OBJ = $(addprefix $(OUT_DIR)/, $(BONUS_SRC:.c=.o))
BONUS_DEPS = $(addprefix $(OUT_DIR)/, $(BONUS_SRC:.c=.d))

ifeq ($(MAKECMDGOALS), bonus)
	OBJS += $(BONUS_OBJ)
	DEPS += $(BONUS_DEPS)
endif

ifeq ($(DEBUG), 1)
CFLAGS		+= -g
else
CFLAGS		+= -O2
endif
IDFLAGS		:= -I$(INCS_DIR)

all: $(NAME) $(NAME_SO)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) rc $@ $^

$(NAME_SO): $(OBJS)
ifeq ($(UNAME_OS), Darwin)
	$(CC) -shared -Wl,-install_name,@rpath/$@ $^ -o $@
else
	$(CC) -shared $^ -o $@
endif

$(OUT_DIR)/%.o: %.c $(LIBFT_H)
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -fPIC -MMD -MP $(IDFLAGS) $< -o $@

clean:
	rm -fr $(OUT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_SO)

re: fclean all

norm: $(LIBFT_H) $(INCS_DIR) $(SRCS)
	@norminette $^

test: test.c
	$(CC) -g -fsanitize=address $< -o $@ -I. -Wl,-rpath . -L. -lft -lm

-include $(DEPS)

.PHONY: all clean fclean re bonus norm test