NAME = cub3D
SRCS =	check_dfs.c \
		check_line.c \
		free_split.c \
		get_map_data.c \
		get_map_info.c \
		error.c \
		main.c 
OBJS = $(SRCS:.c=.o)
OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
LFLAGS = -lmlx -framework OpenGL -framework Appkit -lft -Llibft

LIBFT = libft/libft.a

all : $(NAME)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@make -C libft

$(NAME) : $(OBJS_FILES) $(LIBFT)
	@cc $(CFLAGS) $(LFLAGS) $(OBJS_FILES) -o $(NAME)
	@echo "\033[31mmake cub3D\033[0m"

clean :
	@make -C libft clean
	@rm -rf $(OBJ_DIR)
	@echo "\033[33mclean obj\033[0m"

.PHONY : clean

fclean : clean
	@rm -rf $(LIBFT)
	@rm -rf $(NAME)
	@echo "\033[33mremove cub3D\033[0m"
.PHONY : fclean

re : fclean
	@make all
.PHONY : re