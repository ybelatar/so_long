CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
INCLUDE = -I./includes
VPATH = srcs srcs/map srcs/utils srcs/gui srcs/error_handling srcs/get_next_line srcs/ft_printf
RM = rm -rf
NAME = so_long

UTILS = utils1 utils2
MAP = init_map check_closed check_count check_extension check_rectangle check_winnable
GUI = controls init_gui sprites
ERROR = exit utils_exit
GNL = get_next_line get_next_line_utils
PRINTF = ft_printf printf_utils printf_utils2

SRCS = $(addsuffix .c, $(UTILS))\
	   $(addsuffix .c, $(MAP))\
	   $(addsuffix .c, $(GUI))\
	   $(addsuffix .c, $(ERROR))\
	   $(addsuffix .c, $(GNL))\
	   $(addsuffix .c, $(PRINTF))\
	   main.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR)  $(OBJS)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: all

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus