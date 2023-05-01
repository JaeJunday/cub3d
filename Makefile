NAME = cub3D

CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework Appkit 

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft
	cp libft/$(LIBFT) $(LIBFT)

$(NAME) : $(OBJS) $(LIBFT)
	cc $(LIBFT) $(LFLAGS) $(OBJS) -o $(NAME)

clean :
	make -C libft clean
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)
.PHONY : clean

fclean : clean
	rm -rf libft/$(LIBFT)
	rm -rf $(LIBFT)
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
.PHONY : fclean

re : fclean
	make all
.PHONY : re