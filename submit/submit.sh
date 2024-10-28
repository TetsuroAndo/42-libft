#!/bin/bash

# libftディレクトリが存在する場合は削除
if [ -d "libft" ]; then
    rm -rf libft
fi

# libftディレクトリを作成
mkdir libft

# *.cファイルをlibftディレクトリにコピー
for func in ft_calloc ft_atoi ft_itoa ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_bzero ft_memset ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_strchr ft_strrchr ft_strncmp ft_strnstr ft_strlcpy ft_strlcat ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_strmapi ft_striteri ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
do
    find ../repo/src -name "${func}.c" -exec cp {} libft \;
done

# libft.hとMakefileをlibftディレクトリにコピー
cp ./libft.h ./Makefile libft
# cp ./libft.h ./debag_makefile/Makefile libft
