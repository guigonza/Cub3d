# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 18:02:20 by rdrevar           #+#    #+#              #
#    Updated: 2026/04/21 19:30:04 by rdrevar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

MAKEFLAGS += --no-print-directory

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

CPPFLAGS	= -I./includes -I./$(LIBFT_DIR)/includes -I./$(PRINTF_DIR)/includes -I./$(GNL_DIR)/includes -I./$(MLX_DIR)

LIBFT_DIR	= libs/0.0_libft
PRINTF_DIR	= libs/ft_printf
GNL_DIR		= libs/gnl
MLX_DIR		= libs/mlx_linux


LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/ft_printf.a
GNL			= $(GNL_DIR)/gnl.a
MLX			= $(MLX_DIR)/libmlx_Linux.a

LIBS =	$(GNL) \
		$(PRINTF) \
		$(LIBFT) \
		

FILES		= \
	main \
	render/render_minimap \
	render/animations render/draw_hand_frame \
	render/game_loop render/render \
	utils/free_functions utils/utils \
	utils/cast_ray utils/color \
	utils/helpers utils/get_pixel \
	utils/put_pixel \
	parser/parser parser/parser_init \
	parser/parser_textures parser/parser_map \
	parser/load_game parser/load_handlers \
	parser/load_map

OBJECTS		= $(addprefix srcs/, $(FILES:=.o))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBS) $(MLX) $(OBJECTS)
	@echo "... Compiling $(NAME)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJECTS) \
		$(LIBS) $(MLX) \
		-L/usr/lib -lXext -lX11 -lm \
		-o $(NAME)
	@echo "> Created $(NAME)"

srcs/%.o: srcs/%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(GNL):
	@$(MAKE) -C $(GNL_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR) > /dev/null
	
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -f $(OBJECTS)
	@echo "- Clean $(NAME)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@rm -f $(MLX_DIR)/Makefile.gen $(MLX_DIR)/test/Makefile.gen
	@rm -f $(NAME)
	@echo "- Remove $(NAME)"

re: fclean all

.PHONY: all clean fclean re bonus

###############################################################################
## Basic code metrics.
###############################################################################
# stats:
# 	@lines=$$( \
# 		{ \
# 			find srcs includes -type f \( -name '*.c' -o -name '*.h' -o -name '*.sh' \) -exec cat {} +; \
# 		} | grep -Ev '^[[:space:]]*(#|//|$$)' | wc -l \
# 	); \
# 	echo ""; \
# 	echo "  - Total of lines: \033[0;32m$$lines\033[0m"; \
# 	files=$$( \
# 		find srcs includes -type f \( -name '*.c' -o -name '*.h' -o -name '*.sh' \) | wc -l \
# 	); \
# 	echo "  - Total of files: \033[0;32m$$files\033[0m"; \
# 	echo ""

# test: all
# 	@./tests/test.sh

# debug: all
# 	@./tests/debug.sh