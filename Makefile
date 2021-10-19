SRCS =	main.c \
		map_parser.c \
		map_utils.c \
		file_validator.c \
		error_handler.c \
		mlx_handler.c \
		image_handler.c \
		utils.c \
		render_utils.c \
		cache_utils.c \
		player_cache_handler.c \
		static_cache_handler.c \
		player_handler.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

MLXFLAGS = -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -lbsd

INCLUDES = includes

LIBFTDIR = libft

LIBFT = $(LIBFTDIR)/libft.a

MLX = mlx_linux/libmlx_Linux.a

NAME = so_long

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include/ -Imlx_linux -c $< -o $@

all : $(NAME)

$(LIBFT) :
	@make -C $(LIBFTDIR) all

$(MLX) :
	@make -C mlx_linux

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	@echo "Creating $(NAME).."
	@echo "Your display variable is $$DISPLAY"
	@$(CC) $(CFLAGS) -o $@ $^ $(MLXFLAGS)

clean :
	@echo "Cleaning all .o files.."
	@make -C mlx_linux clean
	@make -C $(LIBFTDIR) clean
	@rm -f $(OBJS)

fclean : clean
	@echo "Cleaning $(NAME)"
	@make -C $(LIBFTDIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re