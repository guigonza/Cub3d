# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 12:41:09 by jomarti3          #+#    #+#              #
#    Updated: 2026/04/21 18:45:46 by rdrevar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_printf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I includes -I../0.0_libft/includes

AR = ar rcs

BASE_FUNCTIONS = \
	ft_is_valid_base \
	ft_dispatch_format ft_printf ft_putnchar

PARSE_FUNCTIONS = \
	ft_parse_decimal_bonus ft_parse_unsigned_bonus \
	ft_parse_char_bonus ft_parse_string_bonus \
	ft_parse_format_bonus

OBJS = $(BASE_FUNCTIONS:=.o) $(PARSE_FUNCTIONS:=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
