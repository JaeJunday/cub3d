NAME = cub3D
SRCS =	/parsing/check_dfs.c \
		/parsing/check_line.c \
		/parsing/free_split.c \
		/parsing/get_map_data.c \
		/parsing/get_map_info.c \
		/parsing/make_map_array.c \
		/error.c \
		/main.c \
		/mlx_hook.c \
		/mlx_start.c \
		/raycasting.c \
		/rotate.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = obj
OBJ_DIRS = obj/parsing
OBJS_FILES = $(addprefix $(OBJ_DIR),$(OBJS))

CC = cc
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address -g
LFLAGS = -lmlx -framework OpenGL -framework Appkit -lft -Llibft

LIBFT = libft/libft.a

all : $(NAME)

$(OBJ_DIRS) :
	mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft

$(NAME) : $(OBJS_FILES) $(LIBFT)
	cc $(CFLAGS) $(LFLAGS) $(OBJS_FILES) -o $(NAME)
	@echo "\033[31mmake cub3D\033[0m"

clean :
	make -C libft clean
	rm -rf $(OBJ_DIR)
	@echo "\033[33mclean obj\033[0m"

.PHONY : clean

fclean : clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)
	@echo "\033[33mremove cub3D\033[0m"

re : fclean
	make all
.PHONY : all clean fclean re
