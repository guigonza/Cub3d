# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 18:02:20 by rdrevar           #+#    #+#              #
#    Updated: 2026/04/24 11:22:39 by guigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

MAKEFLAGS += --no-print-directory

CC			= cc

CFLAGS		= -Wall -Wextra -Werror 

CPPFLAGS	= -I./includes -I./$(LIBFT_DIR)/includes -I./$(GNL_DIR)/includes -I./$(MLX_DIR)

LIBFT_DIR	= libs/0.0_libft
GNL_DIR		= libs/gnl
MLX_DIR		= libs/mlx_linux


LIBFT		= $(LIBFT_DIR)/libft.a
GNL			= $(GNL_DIR)/gnl.a
MLX			= $(MLX_DIR)/libmlx_Linux.a

LIBS =	$(GNL) \
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

$(GNL):
	@$(MAKE) -C $(GNL_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR) > /dev/null
	
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -f $(OBJECTS)
	@echo "- Clean $(NAME)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@rm -f $(MLX_DIR)/Makefile.gen $(MLX_DIR)/test/Makefile.gen
	@rm -f $(NAME)
	@echo "- Remove $(NAME)"

re: fclean all


test: all
	@./tests/test.sh


.PHONY: all clean fclean re bonus test
