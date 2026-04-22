NAME = libft.a

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Werror -Wextra -g
ADSAN = -g -fsanitize=address,undefined
INCLUDE = -I includes

CFLAGS += $(SAN_FLAGS)

SRC		=		src/char_op/ft_isalpha.c \
				src/char_op/ft_isspace.c \
				src/char_op/ft_isdigit.c \
				src/char_op/ft_isalnum.c \
				src/char_op/ft_isascii.c \
				src/char_op/ft_isprint.c \
				src/char_op/ft_toupper.c \
				src/char_op/ft_tolower.c \
				src/strings/ft_strlen.c \
				src/strings/ft_strlcpy.c \
				src/strings/ft_strlcat.c \
				src/strings/ft_strncmp.c \
				src/strings/ft_strcmp.c \
				src/strings/ft_strnstr.c \
				src/strings/ft_strchr.c \
				src/strings/ft_strrchr.c \
				src/not_stdlib/strings/ft_strdup.c \
				src/not_stdlib/strings/ft_substr.c \
				src/not_stdlib/strings/ft_strjoin.c \
				src/not_stdlib/strings/ft_strjoin_char.c \
				src/not_stdlib/strings/ft_strtrim.c \
				src/not_stdlib/strings/ft_split.c \
				src/not_stdlib/strings/ft_strmapi.c \
				src/not_stdlib/strings/ft_striteri.c \
				src/stdlib/mem_op/ft_memset.c \
				src/stdlib/mem_op/ft_bzero.c \
				src/stdlib/mem_op/ft_memcpy.c \
				src/stdlib/mem_op/ft_memmove.c \
				src/stdlib/mem_op/ft_memchr.c \
				src/stdlib/mem_op/ft_memcmp.c \
				src/stdlib/mem_op/ft_calloc.c \
				src/stdlib/ft_atoi.c \
				src/stdlib/ft_atol.c \
				src/stdlib/ft_itoa.c \
				src/not_stdlib/file_op/ft_putchar_fd.c \
				src/not_stdlib/file_op/ft_putstr_fd.c \
				src/not_stdlib/file_op/ft_putendl_fd.c \
				src/not_stdlib/file_op/ft_putnbr_fd.c \
				src/free_utils/ft_free_array.c \
				src/free_utils/ft_free_str_array.c \
				src/free_utils/ft_free_lst.c \
				src/parse_utils/ft_split_quote.c \
				src/parse_utils/ft_strndup_trim_quote.c \
				src/parse_utils/ft_strlen_quote.c \
				src/parse_utils/ft_strtol.c \
				src/parse_utils/ft_strtod.c \
				src/parse_utils/ft_valid_int.c \
				src/parse_utils/ft_utoa_base.c \

SRC_BONUS =		src/list/ft_lstnew_bonus.c \
				src/list/ft_lstadd_front_bonus.c \
				src/list/ft_lstsize_bonus.c \
				src/list/ft_lstlast_bonus.c \
				src/list/ft_lstadd_back_bonus.c \
				src/list/ft_lstdelone_bonus.c \
				src/list/ft_lstclear_bonus.c \
				src/list/ft_lstiter_bonus.c \
				src/list/ft_lstmap_bonus.c

OBJ_DIR = build
OBJECTS		= $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS	= $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

#Define how to build the library
$(NAME): $(OBJECTS)
	@echo "... Building $(NAME)"
	@$(AR) $(NAME) $(OBJECTS)
	@echo "> Created $(NAME)"

bonus: $(OBJECTS) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)

#Define how to compile the object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(SAN_FLAGS) $(INCLUDE) -c $< -o $@

san: clean
	@$(MAKE) SAN_FLAGS="$(ADSAN)"

clean:
	@rm -f $(OBJECTS) $(OBJ_BONUS)
	@rm -rf $(OBJ_DIR)
	@echo "- Clean $(NAME)"

fclean: clean
	@rm -f $(NAME)
	@echo "- Remove $(NAME)"

re: fclean all

.PHONY: all clean fclean re bonus