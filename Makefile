#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 18:09:17 by teando            #+#    #+#              #
#    Updated: 2025/04/16 22:04:06 by teando           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

UNAME_OS	:= $(shell uname -s)
NAME		:= libft.a
AR			:= ar rc
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf
LIBFT_H		:= libft.h
ROOT_DIR	:= .
OUT_DIR		:= $(ROOT_DIR)/out
INCS_DIR	:= $(ROOT_DIR)/incs
IDFLAGS		:= -I$(INCS_DIR)

ifeq ($(UNAME_OS), Darwin)
NAME_SO		:= libft.dylib
else
NAME_SO		:= libft.so
endif

SRCS 		:= \
	$(addprefix $(ROOT_DIR)/, \
		$(addprefix ft_btree/, \
			ft_btree_clear.c \
			ft_btree_del_node.c \
			ft_btree_apply_by_level.c \
			ft_btree_apply_infix.c \
			ft_btree_apply_prefix.c \
			ft_btree_apply_suffix.c \
			ft_btree_create_node.c \
			ft_btree_insert_data.c \
			ft_btree_level_count.c \
			ft_btree_search_item.c \
		) \
		$(addprefix ft_ctype/, \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isblank.c \
			ft_iscntrl.c \
			ft_isdigit.c \
			ft_isgraph.c \
			ft_islower.c \
			ft_ismetachr.c \
			ft_isprint.c \
			ft_ispunct.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_isxdigit.c \
			ft_tolower.c \
			ft_toupper.c \
		) \
		$(addprefix ft_stdio/, \
			ft_putchar_fd.c \
			ft_putchar.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putstrs_endl_fd.c \
			ft_putstrs_fd.c \
			$(addprefix ft_dprintf/, \
				ft_dprintf.c \
				ft_printf.c \
				type_putbase.c \
				type_putchar.c \
				type_putptr.c \
				type_putstr.c \
			) \
		) \
		$(addprefix ft_stdlib/, \
			ft_abs.c \
			ft_atoi.c \
			ft_atol.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_ltoa.c \
			ft_orealloc.c \
			ft_oreallocf.c \
			ft_strs_clear.c \
			ft_qsort.c \
			ft_strtol.c \
			ft_strtoll.c \
			ft_utoa.c \
		) \
		$(addprefix ft_string/, \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_memswap.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strcspn.c \
			ft_strdup.c \
			ft_strdup2.c \
			ft_strfunc.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strjoin2.c \
			ft_strjoin3.c \
			ft_strjoin_free.c \
			ft_strjoin_free2.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strndupex.c \
			ft_strnlen.c \
			ft_strnstr.c \
			ft_strpbrk.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strspn.c \
			ft_strstr.c \
			ft_strtok.c \
			ft_strtok_r.c \
			ft_strtrim.c \
			ft_substr.c \
		) \
		$(addprefix ft_strings/, \
			ft_bzero.c \
			ft_strcasecmp.c\
			ft_strncasecmp.c\
		) \
		$(addprefix ft_utils/, \
			ft_count_strs.c \
			ft_count_words.c \
			ft_substr_l.c \
			ft_substr_r.c \
			ft_max.c \
			ft_min.c \
			ft_strs_dup.c \
			ft_swap.c \
		) \
		$(addprefix get_next_line/, \
			get_next_line.c \
		) \
	)

OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.d))

BONUS_SRC	:= \
	$(addprefix $(ROOT_DIR)/, \
		$(addprefix ft_lst/, \
			ft_create_elem.c \
			ft_list_at.c \
			ft_list_find.c \
			ft_list_foreach.c \
			ft_list_foreach_if.c \
			ft_list_from_strs.c \
			ft_list_last.c \
			ft_list_merge.c \
			ft_list_remove_if.c \
			ft_list_reverse.c \
			ft_list_reverse_fun.c \
			ft_list_size.c \
			ft_list_sort.c \
			ft_list_to_strs.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdel_front.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_sorted_list_insert.c \
			ft_sorted_list_merge.c \
		) \
	)

BONUS_OBJ = $(addprefix $(OUT_DIR)/, $(BONUS_SRC:.c=.o))
BONUS_DEPS = $(addprefix $(OUT_DIR)/, $(BONUS_SRC:.c=.d))
OBJS += $(BONUS_OBJ)
DEPS += $(BONUS_DEPS)

ifeq ($(DEBUG), 1)
CFLAGS		+= -g
else
CFLAGS		+= -O2
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OUT_DIR)/%.o: %.c $(LIBFT_H)
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -fPIC -MMD -MP $(IDFLAGS) $< -o $@

so: $(NAME_SO)

$(NAME_SO): $(OBJS)
ifeq ($(UNAME_OS), Darwin)
	$(CC) -shared -Wl,-install_name,@rpath/$@ $^ -o $@
else
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(IDFLAGS)
	gcc -nostartfiles -shared -o $(NAME_SO) $(OBJS)
endif

clean:
	$(RM) $(OUT_DIR)

fclean: clean
	$(RM) -f $(NAME) $(NAME_SO) a.out

re: fclean all

norm: $(LIBFT_H) $(INCS_DIR) $(SRCS) $(BONUS_SRC)
	@norminette $^

test: test.c
	$(CC) -g -fsanitize=address $< -o $@ -I. -Wl,-rpath . -L. -lft -lm

-include $(DEPS)

.PHONY: all clean fclean re bonus norm test
