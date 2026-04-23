# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 21:38:45 by jomarti3          #+#    #+#              #
#    Updated: 2026/04/21 18:49:00 by rdrevar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = gnl.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I includes -I ../0.0_libft/includes

AR = ar rcs

GNL_FILES = get_next_line
OBJS      = $(GNL_FILES:=.o)

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
