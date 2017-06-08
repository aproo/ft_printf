# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 15:52:59 by vlad              #+#    #+#              #
#    Updated: 2017/04/15 10:07:05 by vmakahon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
FLAGS		= -Wall -Wextra -Werror
CC			= gcc
SRC_PRINT	= src/
SRC_LIB		= libft/
HEADER		= includes/ft_printf.h
HEADER_LIB	= libft/libft.h
OBJ_PRINT	=ft_printf.o \
			analyze_specificar.o \
			create_str_all_char.o \
			create_str_all_string.o \
			create_str_decimal.o \
			create_str_hexadecimal.o \
			create_str_octal.o \
			create_str_pointer.o \
			current_str.o \
			ft_itoa_intmax.o \
			ft_itoa_uintmax.o \
			ft_szero.o \
			identify_specifiers.o \
			print_error.o \
			print_result.o \
			search_flags.o \
			search_length.o \
			search_precision.o \
			search_width.o \
			set_precision.o \
			ft_str_reverse.o \
			ft_int_power.o \
			ft_binary_to_decimal.o \
			convert_utf8.o \
			ft_itoa_uint_max_upper.o \
			add_fixs.o \
			set_precision_str_wide.o \
			ft_free_double_array.o

OBJ_LIBFT	= ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o \
		ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
		ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o \
		ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o \
		ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
		ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
		ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o \
		ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
		ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
		ft_isspace.o ft_memccpy.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o \
		ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_lstdell.o ft_memdup.o \
		ft_max.o ft_islower.o ft_isupper.o

ALL_FILES = $(OBJ_LIBFT) $(OBJ_PRINT)

all: $(NAME)

$(NAME): $(ALL_FILES)
	@ar rc $(NAME) $(ALL_FILES)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(OBJ_LIBFT): %.o: $(SRC_LIB)/%.c
	$(CC) -c $(FLAGS) -I $(HEADER_LIB) $< -o $@

$(OBJ_PRINT): %.o: $(SRC_PRINT)/%.c
	$(CC) -c $(FLAGS) -I $(HEADER_LIB) -I $(HEADER) $< -o $@

clean:
	@rm -f $(ALL_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re		
